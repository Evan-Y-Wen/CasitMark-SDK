#pragma once

#include <QString>
#include <QList>

#include "MCell.h"

namespace Cm3
{
	namespace FormPattern
	{
		class MGroupPattern
		{
		public:
			MGroupPattern();
			~MGroupPattern();

		private:
			QString _groupName;
			QList<MCell> * _cellIndexList;
		};
	}
}

