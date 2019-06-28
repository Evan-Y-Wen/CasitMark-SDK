#pragma once
#include <QList>
#include <QVariant>

class PatternNode
{
public:
	enum Type {
		Root,
		FileName
	};
	PatternNode(Type type, const QString &str = "");
	~PatternNode();
	Type type;
	QString str;
	PatternNode *parent;
	QList<PatternNode *> children;
};
