#include "document.h"

Document::Document() : title("Без имени") {}
Document::~Document() {}
QString Document::GetTitle() const { return title; }