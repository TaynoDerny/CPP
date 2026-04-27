#include "GraphicDocument.h"
#include <QPixmap>

GraphicDocument::GraphicDocument(QWidget *parent) : Document(parent) {
    imageLabel = new QLabel(this);
    scrollArea = new QScrollArea(this);
    scrollArea->setWidget(imageLabel);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(scrollArea);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

bool GraphicDocument::openFile(const QString &path) {
    QPixmap pixmap(path);
    if (pixmap.isNull()) return false;

    imageLabel->setPixmap(pixmap);
    imageLabel->resize(pixmap.size());
    filePath = path;
    setWindowTitle(path);
    return true;
}

bool GraphicDocument::saveFile(const QString &path) {
    if (!imageLabel->pixmap().isNull()) {
        filePath = path;
        setWindowTitle(path);
        return imageLabel->pixmap().save(path);
    }
    return false;
}