#include "MPattern.h"
using namespace Cm3::FormPattern;

#include <QUuid>
#include <QDebug>

MPattern::MPattern() :
	_isInitialized(false),
	_formPatterns(nullptr)
{
}


MPattern::~MPattern()
{
}


bool MPattern::Initialize()
{
	_formPatterns = new QList<MFormPattern *>;
	_isInitialized = true;
	return true;
}


void MPattern::Release()
{
	delete _formPatterns;
	_isInitialized = false;
}


void MPattern::CreatePattern()
{
	_patternGUID = QUuid::createUuid().toString();// È«ÇòÎ¨Ò»Âë
	qDebug() << _patternGUID;
}


void MPattern::AddPattern()
{

}
