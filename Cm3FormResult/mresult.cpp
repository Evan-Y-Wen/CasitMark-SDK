#include "mresult.h"
using namespace Cm3::FormResult;


MResult::MResult():
	_isInitialized(false),
	_validFormCount(0),
	_formReuslts(nullptr)
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
	return true;
}

void MResult::Release()
{
	if (_formReuslts != nullptr)
	{
		delete _formReuslts;
	}
	_formReuslts = nullptr;
}
