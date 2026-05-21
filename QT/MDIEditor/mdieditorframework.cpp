#include "mdieditorframework.h"
#include "ui_mdieditorframework.h"

#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>

MDIEditorFramework::MDIEditorFramework(QWidget* parent)
    : QMainWindow(parent)
    , m_mdiArea(nullptr)
    , m_currentDocument(nullptr)
{
    setupUI();
    createConnections();
}

MDIEditorFramework::~MDIEditorFramework()
{
}

void MDIEditorFramework::setupUI()
{
    // Создаем MDI область
    m_mdiArea = new QMdiArea(this);
    setCentralWidget(m_mdiArea);

    // Создаем меню
    QMenu* fileMenu = menuBar()->addMenu(tr("Файл"));

    fileMenu->addAction(tr("Создать"), this, &MDIEditorFramework::newDocument,
                        QKeySequence::New);
    fileMenu->addAction(tr("Открыть..."), this, &MDIEditorFramework::openDocument,
                        QKeySequence::Open);
    fileMenu->addAction(tr("Сохранить"), this, &MDIEditorFramework::saveDocument,
                        QKeySequence::Save);
    fileMenu->addAction(tr("Сохранить как..."), this, &MDIEditorFramework::saveDocumentAs,
                        QKeySequence::SaveAs);
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Печать..."), this, &MDIEditorFramework::printDocument,
                        QKeySequence::Print);
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Закрыть"), this, &MDIEditorFramework::closeDocument,
                        QKeySequence::Close);
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Выход"), qApp, &QApplication::quit,
                        QKeySequence::Quit);

    // Панель инструментов
    QToolBar* toolBar = addToolBar(tr("Панель инструментов"));
    toolBar->addAction(tr("Создать"), this, &MDIEditorFramework::newDocument);
    toolBar->addAction(tr("Открыть"), this, &MDIEditorFramework::openDocument);
    toolBar->addAction(tr("Сохранить"), this, &MDIEditorFramework::saveDocument);
    toolBar->addAction(tr("Печать"), this, &MDIEditorFramework::printDocument);

    // Строка состояния
    statusBar()->showMessage(tr("Готов"));
}

void MDIEditorFramework::createConnections()
{
    connect(m_mdiArea, &QMdiArea::subWindowActivated, this,
            [this](QMdiSubWindow* window) {
                if (window) {
                    m_currentDocument = qobject_cast<AbstractDocument*>(window->widget());
                } else {
                    m_currentDocument = nullptr;
                }
            });
}

void MDIEditorFramework::newDocument()
{
    // Создаем документ используя Factory Method
    AbstractDocument* doc = createDocument();
    if (!doc) {
        QMessageBox::warning(this, tr("Ошибка"),
                             tr("Не удалось создать документ"));
        return;
    }

    // Добавляем документ в MDI область
    QMdiSubWindow* subWindow = m_mdiArea->addSubWindow(doc->getViewWidget());
    subWindow->setWindowTitle(doc->getTitle());
    subWindow->show();

    m_currentDocument = doc;
    statusBar()->showMessage(tr("Создан новый документ"));
}

void MDIEditorFramework::openDocument()
{
    if (!m_currentDocument) {
        QMessageBox::warning(this, tr("Ошибка"),
                             tr("Сначала создайте документ"));
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть документ"));
    if (!fileName.isEmpty()) {
        if (m_currentDocument->open(fileName)) {
            m_mdiArea->activeSubWindow()->setWindowTitle(m_currentDocument->getTitle());
            statusBar()->showMessage(tr("Документ открыт: ") + fileName);
        } else {
            QMessageBox::critical(this, tr("Ошибка"),
                                  tr("Не удалось открыть документ"));
        }
    }
}

void MDIEditorFramework::saveDocument()
{
    if (!m_currentDocument) {
        QMessageBox::warning(this, tr("Ошибка"),
                             tr("Нет активного документа"));
        return;
    }

    if (m_currentDocument->save()) {
        statusBar()->showMessage(tr("Документ сохранен"));
    } else {
        QMessageBox::critical(this, tr("Ошибка"),
                              tr("Не удалось сохранить документ"));
    }
}

void MDIEditorFramework::saveDocumentAs()
{
    if (!m_currentDocument) {
        QMessageBox::warning(this, tr("Ошибка"),
                             tr("Нет активного документа"));
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить документ как"));
    if (!fileName.isEmpty()) {
        if (m_currentDocument->saveAs(fileName)) {
            m_mdiArea->activeSubWindow()->setWindowTitle(m_currentDocument->getTitle());
            statusBar()->showMessage(tr("Документ сохранен как: ") + fileName);
        } else {
            QMessageBox::critical(this, tr("Ошибка"),
                                  tr("Не удалось сохранить документ"));
        }
    }
}

void MDIEditorFramework::printDocument()
{
    if (!m_currentDocument) {
        QMessageBox::warning(this, tr("Ошибка"),
                             tr("Нет активного документа"));
        return;
    }

    m_currentDocument->print();
    statusBar()->showMessage(tr("Печать документа"));
}

void MDIEditorFramework::closeDocument()
{
    QMdiSubWindow* activeWindow = m_mdiArea->activeSubWindow();
    if (activeWindow) {
        activeWindow->close();
        statusBar()->showMessage(tr("Документ закрыт"));
    }
}