#include "abstractdocument.h"

AbstractDocument::AbstractDocument(QObject* parent)
    : QObject(parent)
    , m_isModified(false)
{
}

AbstractDocument::~AbstractDocument()
{
}