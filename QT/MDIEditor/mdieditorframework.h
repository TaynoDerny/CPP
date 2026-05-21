#ifndef MDIEDITORFRAMEWORK_H
#define MDIEDITORFRAMEWORK_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include "abstractdocument.h"

class MDIEditorFramework : public QMainWindow
{
    Q_OBJECT

public:
    explicit MDIEditorFramework(QWidget* parent = nullptr);
    ~MDIEditorFramework();

protected:
    QMdiArea* m_mdiArea;
    AbstractDocument* m_currentDocument;

    // Factory Method - должен быть реализован в потомках
    virtual AbstractDocument* createDocument() = 0;

protected slots:
    void newDocument();
    void openDocument();
    void saveDocument();
    void saveDocumentAs();
    void printDocument();
    void closeDocument();

private:
    void setupUI();
    void createConnections();
};

#endif // MDIEDITORFRAMEWORK_H