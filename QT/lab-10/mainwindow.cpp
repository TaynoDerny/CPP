#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QTime>
#include <QPainter>
#include <QTimer>
#include <QStringList>
#include <QVector>
#include <numeric>
#include <algorithm>

class ClockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClockWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [=](){
            this->update();
        });
        timer->start(1000);
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        int side = qMin(width(), height());
        painter.translate(width() / 2, height() / 2);
        painter.scale(side / 200.0, side / 200.0);

        painter.setPen(QPen(Qt::black, 2));
        painter.drawEllipse(-90, -90, 180, 180);

        for (int i = 0; i < 12; ++i) {
            painter.drawLine(88, 0, 96, 0);
            painter.rotate(30.0);
        }

        QTime time = QTime::currentTime();

        painter.setPen(QPen(Qt::red, 1));
        double secondsAngle = (time.second() / 60.0) * 360.0;

        painter.save();
        painter.rotate(secondsAngle);
        painter.drawLine(0, 0, 0, -75);
        painter.restore();
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    QPushButton *btnGenerate = new QPushButton("Сгенерировать случайные числа (1..20)", this);
    layout->addWidget(btnGenerate);

    txtNumbers = new QTextEdit(this);
    txtNumbers->setReadOnly(true);
    layout->addWidget(txtNumbers);

    clockWidget = new ClockWidget(this);
    clockWidget->setMinimumSize(150, 150);
    layout->addWidget(clockWidget);

    connect(btnGenerate, &QPushButton::clicked, this, &MainWindow::generateNumbers);
}

MainWindow::~MainWindow() {}

void MainWindow::generateNumbers()
{
    QVector<int> numbers(20);
    std::iota(numbers.begin(), numbers.end(), 1);

    for (int i = 19; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(numbers[i], numbers[j]);
    }

    QStringList strList;
    for (int num : numbers) {
        strList << QString::number(num);
    }

    txtNumbers->setPlainText("Результат: " + strList.join(", "));
}

#include "mainwindow.moc"