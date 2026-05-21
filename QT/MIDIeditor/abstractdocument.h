#ifndef ABSTRACTDOCUMENT_H
#define ABSTRACTDOCUMENT_H

#include <QObject>
#include <QWidget>
#include <QString>

class AbstractDocument : public QObject
{
    Q_OBJECT

public:
    explicit AbstractDocument(QObject* parent = nullptr);
    virtual ~AbstractDocument();

    // Основные операции с документом
    virtual bool open(const QString& fileName) = 0;
    virtual bool save() = 0;
    virtual bool saveAs(const QString& fileName) = 0;
    virtual void print() = 0;
    virtual void close() = 0;

    // Получение виджета документа и заголовка
    virtual QWidget* getViewWidget() = 0;
    virtual QString getTitle() const = 0;

protected:
    QString m_fileName;
    bool m_isModified;
};

#endif // ABSTRACTDOCUMENT_H