#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

namespace Cm2
{
	namespace FormPatternMaker
	{
		class CasitMarkPatternActionManager
		{   /*
			/// <summary>
			/// 所有动作
			/// </summary>
		private:
			static unordered_map<string,> *m_patternActions = new Hashtable();

			/// <summary>
			/// 当前使用的动作记录
			/// </summary>
		private:
			static PatternAction m_currentPatternAction = null;

			/// <summary>
			/// 产生新的模式动作记录
			/// </summary>
			/// <param name="iPatternGUID"></param>
		public:
			static void CreatePatternAction(Cm2::FormPattern::MPattern &iPattern)
			{
				m_currentPatternAction = new PatternAction();
				for (Int32 i = 0; i < iPattern.FormPatterns.Count; ++i)
					m_currentPatternAction.AddFormAction();
				m_patternActions.Add(iPattern.PatternGUID, m_currentPatternAction);
			}

			/// <summary>
			/// 删除模式动作记录
			/// </summary>
			/// <param name="iPatternGUID"></param>
		public:
			static void RemovePatternAction(String iPatternGUID)
			{
				m_patternActions.Remove(iPatternGUID);
			}

		public:
			static void AddFromAction()
			{
				m_currentPatternAction.AddFormAction();
			}

		public:
			static void InsertFormRange(Int32 iPosition, List<FormAction> iFormActions)
			{
				m_currentPatternAction.InsertFormActionRange(iPosition, iFormActions);
			}

			/// <summary>
			/// 删除当前表单记录
			/// </summary>
			/// <param name="index"></param>
		public:
			static void RemoveFormAction(Int32 index)
			{
				m_currentPatternAction.RemoveFormAction(index);
			}

			/// <summary>
			/// 激活模式动作记录
			/// </summary>
			/// <param name="iPatternGUID"></param>
			/// <param name="iFormIndex"></param>
		public:
			static void ActivePatternAction(String iPatternGUID, Int32 iFormIndex)
			{
				m_currentPatternAction = m_patternActions[iPatternGUID] as PatternAction;
				m_currentPatternAction.SelectFormByIndex(iFormIndex);
			}

		public:
			static void Undo()
			{
				m_currentPatternAction.UndoHappen();
			}

		public:
			static void Redo()
			{
				m_currentPatternAction.RedoHappen();
			}

		public:
			static void NewAction(ActionInterface iAction)
			{
				FormAction fa = m_currentPatternAction.SelectFormByIndex(App.TheMainWindow.s_CurrentSelectedFormIndex);
				if (fa != null)
					fa.NewActionProduce(iAction);
			}

		public:
			static void ClearCurrentActions()
			{
				FormAction fa = m_currentPatternAction.SelectFormByIndex(App.TheMainWindow.s_CurrentSelectedFormIndex);
				if (fa != null)
					fa.ClearActions();
			}*/
		};
	}
}


