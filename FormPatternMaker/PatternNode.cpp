#include "PatternNode.h"
#include <QtGui>
PatternNode::PatternNode(Type type, const QString &str)
{
	this->type = type;
	this->str = str;
	this->parent = 0;
}
PatternNode::~PatternNode()
{
	qDeleteAll(this->children);
}

