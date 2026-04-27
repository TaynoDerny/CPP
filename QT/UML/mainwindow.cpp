#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionNewText_triggered() {
    TextDocument *doc = new TextDocument(this);
    doc->setWindowTitle("Новый документ.txt");
    ui->mdiArea->addSubWindow(doc);
    doc->show();
}

void MainWindow::on_actionOpenText_triggered() {
    QString path = QFileDialog::getOpenFileName(this, "Открыть текст", "", "Text Files (*.txt);;All Files (*)");
    if (!path.isEmpty()) {
        TextDocument *doc = new TextDocument(this);
        doc->openFile(path);
        ui->mdiArea->addSubWindow(doc);
        doc->show();
    }
}

void MainWindow::on_actionOpenImage_triggered() {
    QString path = QFileDialog::getOpenFileName(this, "Открыть картинку", "", "Images (*.png *.jpg *.bmp)");
    if (!path.isEmpty()) {
        GraphicDocument *doc = new GraphicDocument(this);
        doc->openFile(path);
        ui->mdiArea->addSubWindow(doc);
        doc->show();
    }
}


void MainWindow::on_actionSave_triggered() {
    // Получаем активное окно
    QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow();
    if (!activeSubWindow) return;

    Document *doc = qobject_cast<Document*>(activeSubWindow->widget());
    if (doc) {
        if (doc->currentFilePath().isEmpty()) {
            on_actionSaveAs_triggered(); // Если файл новый, вызываем "Сохранить как"
        } else {
            doc->saveFile(doc->currentFilePath()); // Каркас сам решит, текст это или картинка
        }
    }
}

void MainWindow::on_actionSaveAs_triggered() {
    QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow();
    if (!activeSubWindow) return;

    Document *doc = qobject_cast<Document*>(activeSubWindow->widget());
    if (doc) {
        QString path = QFileDialog::getSaveFileName(this, "Сохранить как...");
        if (!path.isEmpty()) {
            doc->saveFile(path);
        }
    }
}

void MainWindow::on_actionCopy_triggered() {
    QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow();
    if (!activeSubWindow) return;

    TextDocument *textDoc = qobject_cast<TextDocument*>(activeSubWindow->widget());
    if (textDoc) {
        textDoc->getTextEdit()->copy();
    }
}
