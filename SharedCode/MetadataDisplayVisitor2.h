#pragma once
// declaration of MetadataDisplayVisitor2 here
#include "AbstractFileVisitor.h"


class MetadataDisplayVisitor2 :public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*) override;
	virtual void visit_ImageFile(ImageFile*) override;
};