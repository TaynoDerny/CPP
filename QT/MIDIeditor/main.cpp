#include <QApplication>
#include <QMessageBox>
#include "mdieditorframework.h"

// ВРЕМЕННЫЙ класс для демонстрации каркаса
// В реальном проекте вы создадите TextEditorApp и GraphicEditorApp
class TempDocument : public AbstractDocument
{
public:
    TempDocument(QObject* parent = nullptr) : AbstractDocument(parent) {}

    bool open(const QString& fileName) override {
        m_fileName = fileName;
        return true;
    }

    bool save() override { return true; }
    bool saveAs(const QString& fileName) override {
        m_fileName = fileName;
        return true;
    }

    void print() override {}
    void close() override {}

    QWidget* getViewWidget() override {
        return new QWidget();
    }

    QString getTitle() const override {
        return m_fileName.isEmpty() ? "Без названия" : m_fileName;
    }
};

// Временный фреймворк для теста
class TempEditor : public MDIEditorFramework
{
public:
    TempEditor(QWidget* parent = nullptr) : MDIEditorFramework(parent) {}

protected:
    AbstractDocument* createDocument() override {
        return new TempDocument(this);
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Показываем сообщение о том, что это каркас
    QMessageBox::information(nullptr, "Каркас готов!",
                             "Каркас MDI-редактора создан!\n\n"
                             "Теперь нужно создать:\n"
                             "1. TextEditorApp (для текстовых документов)\n"
                             "2. GraphicEditorApp (для графических документов)\n\n"
                             "Каждый должен наследоваться от MDIEditorFramework\n"
                             "и реализовать метод createDocument()");

    TempEditor editor;
    editor.setWindowTitle("MDI Editor Framework (Demo)");
    editor.resize(1024, 768);
    editor.show();

    return app.exec();
}