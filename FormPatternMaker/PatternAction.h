#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <list>
using namespace std;


namespace Cm2
{
	namespace FormPatternMaker

	{
		
		class PatternAction
		{/*
			/// <summary>
			/// 选择表单的索引
			/// </summary>
		private:
			int32_t m_selectFormIndex = 0;

			/// <summary>
			/// 表单动作记录
			/// </summary>
		private:
			list<FormAction> m_actionsInForm = new list<FormAction>();

		public:
			void AddFormAction()
			{
				m_actionsInForm.Add(new FormAction());
			}

			public void InsertFormActionRange(int32_t iPosition, list<FormAction> iFormActions)
			{
				m_actionsInForm.InsertRange(iPosition, iFormActions);
			}

			public void RemoveFormAction(int32_t index)
			{
				m_actionsInForm.RemoveAt(index);
			}

			/// <summary>
			/// 选择的当前操作表单
			/// </summary>
			/// <param name="index"></param>
			public FormAction SelectFormByIndex(int32_t index)
			{
				if (index >= m_actionsInForm.Count)
				{
					((MainWindow)(App.Current.MainWindow)).Button_Undo.IsEnabled = false;
					((MainWindow)(App.Current.MainWindow)).Button_Redo.IsEnabled = false;
					return null;
				}
				m_selectFormIndex = index;
				if (m_actionsInForm[m_selectFormIndex].CanUndo())
				{
					((MainWindow)(App.Current.MainWindow)).Button_Undo.IsEnabled = true;
				}
				else
				{
					((MainWindow)(App.Current.MainWindow)).Button_Undo.IsEnabled = false;
				}

				if (m_actionsInForm[m_selectFormIndex].CanRedo())
				{
					((MainWindow)(App.Current.MainWindow)).Button_Redo.IsEnabled = true;
				}
				else
				{
					((MainWindow)(App.Current.MainWindow)).Button_Redo.IsEnabled = false;
				}

				return m_actionsInForm[m_selectFormIndex];
			}

			public void UndoHappen()
			{
				m_actionsInForm[m_selectFormIndex].ActionUndo();
			}

			public void RedoHappen()
			{
				m_actionsInForm[m_selectFormIndex].ActionRedo();
			}*/
		};
	}
}
