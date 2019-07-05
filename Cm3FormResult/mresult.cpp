#include "mresult.h"
using namespace Cm3::FormResult;


MResult::MResult():
	_isInitialized(false),
	_validFormCount(0),
	_formReuslts(nullptr),
	_formImageFiles(nullptr)
{
}

MResult::~MResult()
{
}

bool MResult::Initialize()
{
	_isInitialized = true;
	_validFormCount = 0;
	_formReuslts = new QList<MFormResult *>;
	_formImageFiles = new QList<MFormImageFile *>;
	return true;
}

void MResult::Release()
{
	if (_formReuslts != nullptr)
	{
		delete _formReuslts;
	}
	if (_formImageFiles != nullptr)
	{
		delete _formImageFiles;
	}
	_formReuslts = nullptr;
	_formImageFiles = nullptr;
}
