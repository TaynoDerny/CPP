#include "texteditor.h"
#include "textdocument.h"

Document* TextEditor::CreateDocument() {
    return new TextDocument();
}