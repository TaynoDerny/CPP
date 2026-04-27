#ifndef GRAPHICDOCUMENT_H
#define GRAPHICDOCUMENT_H

#include "Document.h"
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>

class GraphicDocument : public Document {
    Q_OBJECT
public:
    explicit GraphicDocument(QWidget *parent = nullptr);
    bool openFile(const QString &path) override;
    bool saveFile(const QString &path) override;
    QString currentFilePath() const override { return filePath; }

private:
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QString filePath;
};

#endif // GRAPHICDOCUMENT_H