#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
 
class BasicDisplayVisitor:public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile*) override;
	virtual void visit_ImageFile(ImageFile*) override;
};