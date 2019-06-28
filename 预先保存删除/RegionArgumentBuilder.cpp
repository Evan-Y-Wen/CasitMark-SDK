#include "RegionArgumentBuilder.h"
#include <vector>
Cm2::FormPatternMaker::RegionArgumentBuilder::RegionArgumentBuilder()
{
	S_lastMarkRegion = nullptr;
	S_region = nullptr;
	s_allChangeMatrix = new unordered_set<string>;
	centerX = 0.0;
	centerY = 0.0;
	barCodeValue = "";
	IsMark = false;
	IsCheck = false;
	indexSeven = -1;
	indexSycn = -1;
}


Cm2::FormPatternMaker::RegionArgumentBuilder::~RegionArgumentBuilder()
{
}

Cm2::FormPattern::MRegion *Cm2::FormPatternMaker::RegionArgumentBuilder::BuildRegionArgument(QRect & iRect, Cm2::FormPatternMaker::EnumSet::RecognizeType & iType)
{
	iRect.setX(round(iRect.x()));
	iRect.setY(round(iRect.y()));
	iRect.setWidth(round(iRect.width()));
	iRect.setHeight(round(iRect.height()));

	if (iRect.width() < 5.0 || iRect.height() < 5.0)
		return nullptr;
	/*
	switch (iType)
	{
	case EnumSet::RecognizeType::LocationMark:
		return BuildLocationMarkRegionArgument(iRect);
	case EnumSet::RecognizeType::Mark:
		return BuildMarkRegionArgument(iRect, IsMark);
	case EnumSet::RecognizeType::MarkRegion:
		return BuildMarkRegionArgument(iRect);
	case EnumSet::RecognizeType::ImageShot:
		return BuildImageshotArgument(iRect);
	case EnumSet::RecognizeType::OCR:
		return BuildOCRArgument(iRect);
	case EnumSet::RecognizeType::BarOr2DCode:
		return BuildBarOr2DCodeArgument(iRect);
	case EnumSet::RecognizeType::Seven:
		return BuildSevenArgument(iRect);
	case EnumSet::RecognizeType::SyncRow:
		return BuildSycnArgument(iRect);
	}*/

	return nullptr;
}
/*

Cm2::FormPattern::MRegion * Cm2::FormPatternMaker::RegionArgumentBuilder::BuildLocationMarkRegionArgument(QRect & iRect, bool iRemoveOldNode)
{
	int QRCodeValue = -1;
	int CloseCodeValue = -1;
	Cm2::FormPattern::MRegion *Sregion = new Cm2::FormPattern::MRegion();
	Cm2::FormPattern::MRegion *Eregion = new Cm2::FormPattern::MRegion();
	Cm2::FormPattern::MRegion *ShapeRegion = new Cm2::FormPattern::MRegion();
	Cm2::FormPattern::MRegion *SShapeRegion = new Cm2::FormPattern::MRegion();
	Cm2::FormPattern::MRegion *EShapeRegion = new Cm2::FormPattern::MRegion();
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern == nullptr)
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern = new FormPattern::MLocatePattern();
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->StartSearchRegion == nullptr)
	{
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->StartSearchRegion = Sregion;
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->StartShapeRegion = SShapeRegion;
	}																				  
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->EndSearchRegion == nullptr)
	{
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->EndSearchRegion = Eregion;
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->EndShapeRegion = EShapeRegion;
	}


	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->StartSearchRegion->Name == "")
	{
		Sregion->Name = "��ʼ��λ���";
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->StartSearchRegion->Name = "��ʼ��λ���";
		Sregion->X = (int32_t)round(iRect.x());
		Sregion->Y = (int32_t)round(iRect.y());
		Sregion->Width = (int32_t)round(iRect.width());
		Sregion->Height = (int32_t)round(iRect.height());
		Sregion->BorderColor = "#FF000000";//Colors.Black.ToString();
		Sregion->BackgroundColor = "#FF0000FF";// Colors.Blue.ToString();
	}
	else
	{
		if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->StartSearchRegion->Name == "��ʼ��λ���")
		{
			Eregion->Name = "������λ���";
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->EndSearchRegion->Name = "������λ���";
			Eregion->X = (int32_t)round(iRect.x());
			Eregion->Y = (int32_t)round(iRect.y());
			Eregion->Width = (int32_t)round(iRect.width());
			Eregion->Height = (int32_t)round(iRect.height());
			Eregion->BorderColor = "#FF000000";//Colors.Black.ToString();
			Eregion->BackgroundColor = "#FF0000FF";// Colors.Blue.ToString();
		}
		else
		{
			Sregion->Name = "��ʼ��λ���";
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern->StartSearchRegion->Name = "��ʼ��λ���";
			Sregion->X = (int32_t)round(iRect.x());
			Sregion->Y = (int32_t)round(iRect.y());
			Sregion->Width = (int32_t)round(iRect.width());
			Sregion->Height = (int32_t)round(iRect.height());
			Sregion->BorderColor = "#FF000000";//Colors.Black.ToString();
			Sregion->BackgroundColor = "#FF0000FF";// Colors.Blue.ToString();
		}
	}
	unsigned char *getImg = nullptr;//Byte[] getImg = nullptr;
	if (_CurrentEditPattern->LocateMode == FormPattern::MLocateMode::SimpleCodeForLocateMode)
	{
		try
		{
			if (Sregion->Name == "��ʼ��λ���")
			{
				QRCodeValue = FormPatternMakerHelper[s_CurrentSelectedFormIndex].SimpleCodeRecognizeOnRegion(Sregion, ref centerX, ref centerY);
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartShapeRegion.X = Convert.ToInt32(centerX);
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartShapeRegion.Y = Convert.ToInt32(centerY);
			}
			else if (Eregion->Name == "������λ���")
			{
				QRCodeValue = FormPatternMakerHelper[s_CurrentSelectedFormIndex].SimpleCodeRecognizeOnRegion(Eregion, ref centerX, ref centerY);
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndShapeRegion.X = Convert.ToInt32(centerX);
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndShapeRegion.Y = Convert.ToInt32(centerY);
			}

		}
		catch (System.Exception ex)
		{

		}
	}
	else
	{
		try
		{
			if (Sregion.Name == "��ʼ��λ���")
			{
				//ShapeRegion = FormPatternMakerHelper[s_CurrentSelectedFormIndex].FindFirstClosedShapeOnRegion(Sregion);
				//if (ShapeRegion == nullptr)
				//    return nullptr;
				//else
				//    getImg = FormPatternMakerHelper[s_CurrentSelectedFormIndex].GetRectImg(ShapeRegion);
				CloseCodeValue = FormPatternMakerHelper[s_CurrentSelectedFormIndex].ClosedShapeRecognizeOnRegion(Sregion, ref centerX, ref centerY);
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartShapeRegion.X = Convert.ToInt32(centerX);
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartShapeRegion.Y = Convert.ToInt32(centerY);
			}
			else if (Eregion.Name == "������λ���")
			{
				//ShapeRegion = FormPatternMakerHelper[s_CurrentSelectedFormIndex].FindFirstClosedShapeOnRegion(Eregion);
				//if (ShapeRegion == nullptr)
				//    return nullptr;
				//else
				//    getImg = FormPatternMakerHelper[s_CurrentSelectedFormIndex].GetRectImg(ShapeRegion);
				CloseCodeValue = FormPatternMakerHelper[s_CurrentSelectedFormIndex].ClosedShapeRecognizeOnRegion(Eregion, ref centerX, ref centerY);
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndShapeRegion.X = Convert.ToInt32(centerX);
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndShapeRegion.Y = Convert.ToInt32(centerY);
			}
		}
		catch (System.Exception ex)
		{
		}

	}

	((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "��λ��־���ѡ�����";
	LocationRegionArguments LregionArgWnd = new LocationRegionArguments();
	if (_CurrentEditPattern.LocateMode == FormPattern.MLocateMode.SimpleCode)
	{
		if (QRCodeValue < 0)
		{
			SelfDefineUC.MetroStyleMessageBox.ShowMessageBox_Ok(nullptr, "��ѡλ�����������¿�ѡ��", "Error");
		}
		else
		{
			LregionArgWnd.Owner = App.Current.MainWindow;
			if (Sregion.Name == "��ʼ��λ���")
				LregionArgWnd.Initial(ref Sregion, QRCodeValue);
			if (Eregion.Name == "������λ���")
				LregionArgWnd.Initial(ref Eregion, QRCodeValue);
			LregionArgWnd.ShowDialog();
		}
	}
	else
	{
		if (CloseCodeValue < 0)
		{
			SelfDefineUC.MetroStyleMessageBox.ShowMessageBox_Ok(nullptr, "��ѡλ�����������¿�ѡ��", "Error");
		}
		else
		{
			LregionArgWnd.Owner = App.Current.MainWindow;
			if (Sregion.Name == "��ʼ��λ���")
				LregionArgWnd.Initial1(ref Sregion, CloseCodeValue);
			if (Eregion.Name == "������λ���")
				LregionArgWnd.Initial1(ref Eregion, CloseCodeValue);
			LregionArgWnd.ShowDialog();
			//if (Sregion.Name == "��ʼ��λ���")
			//    LregionArgWnd.Initial(ref Sregion, ShapeRegion, getImg);
			//if (Eregion.Name == "������λ���")
			//    LregionArgWnd.Initial(ref Eregion, ShapeRegion, getImg);
		}
	}


	if (!LregionArgWnd.m_SuccessCreate)
	{

		if (_CurrentEditPattern.LocateMode == FormPattern.MLocateMode.SimpleCode)
		{

			if (Sregion.Name == "��ʼ��λ���")
			{
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartSearchRegion = new FormPattern.MRegion();
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartSimpleCodeValue = -1;
			}
			else if (Eregion.Name == "������λ���")
			{
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndSearchRegion = new FormPattern.MRegion();
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndSimpleCodeValue = -1;
			}
		}
		else
		{
			if (Sregion.Name == "��ʼ��λ���")
			{
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartSearchRegion = new FormPattern.MRegion();
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartShapeRegion = new FormPattern.MRegion();
			}
			else if (Eregion.Name == "������λ���")
			{
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndSearchRegion = new FormPattern.MRegion();
				(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndShapeRegion = new FormPattern.MRegion();
			}
		}
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern = nullptr;
		((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "�˴ο�ѡʧ�ܣ������¿�ѡ��";
		return nullptr;
	}

	// �ɹ��������������ʾ
	if (_CurrentEditPattern.LocateMode == FormPattern.MLocateMode.SimpleCode)
	{
		if (Sregion.Name == "��ʼ��λ���")
		{
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartSearchRegion = Sregion;
			CreateRegionTreeViewItem(EnumSet.RecognizeType.LocationMark, Sregion);
		}
		else if (Eregion.Name == "������λ���")
		{
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndSearchRegion = Eregion;
			CreateRegionTreeViewItem(EnumSet.RecognizeType.LocationMark, Eregion);
		}
	}
	else
	{
		if (Sregion.Name == "��ʼ��λ���")
		{
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartSearchRegion = Sregion;
			CreateRegionTreeViewItem(EnumSet.RecognizeType.LocationMark, Sregion);
		}
		else if (Eregion.Name == "������λ���")
		{
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndSearchRegion = Eregion;
			CreateRegionTreeViewItem(EnumSet.RecognizeType.LocationMark, Eregion);
		}
	}


	_CurrentEditFormPattern = (*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex];
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.StartSearchRegion.Name != ""
		&& (*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].LocatePattern.EndSearchRegion.Name != "")
	{
		EnableOperationFunction();
		Button_SaveFile.IsEnabled = true;
		Button_AddLocationRegion.IsEnabled = false;
		Button_AddMark.IsEnabled = true;
		Button_AddOCRRegion.IsEnabled = true;
		Button_AddImageShotRegion.IsEnabled = true;
		Button_AddBarCodeRegion.IsEnabled = true;
		Button_Add7Region.IsEnabled = true;
		Button_AddSycnRRegion.IsEnabled = true;

		((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "��λ���ѡ��ɣ����������ʶ������";
		return Eregion;
	}
	else
	{
		((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "��λ���ѡδ��ɣ������ѡ1����";
		return Sregion;
	}
}

Cm2::FormPattern::MRegion * Cm2::FormPatternMaker::RegionArgumentBuilder::BuildMarkRegionArgument(QRect & iRect)
{
	//��һ����տ�
	Cm2.FormPattern.MRegion firstRegion = new FormPattern.MRegion();
	// ������λ������Ϣ
	Cm2.FormPattern.MRegion region = new Cm2.FormPattern.MRegion();
	region.Name = "��Ϳ������";
	region.X = (int32_t)Math.Round(iRect.X);
	region.Y = (int32_t)Math.Round(iRect.Y);
	region.Width = (int32_t)Math.Round(iRect.Width);
	region.Height = (int32_t)Math.Round(iRect.Height);
	region.BorderColor = Colors.Black.ToString();
	region.BackgroundColor = Colors.Blue.ToString();


	//ʶ�������ڵ�һ���������
	firstRegion = FormPatternMakerHelper[s_CurrentSelectedFormIndex].FindFirstClosedShapeOnRegion(region);
	if (firstRegion != nullptr)
	{
		firstRegion.BorderColor = Colors.Black.ToString();
		firstRegion.BackgroundColor = Colors.Blue.ToString();
		//��ʾ�պϿ���Ϣ
		ShowMarkArguments SMA = new ShowMarkArguments();
		SMA.Initial(firstRegion);
		if (!IsMark)
		{
			SMA.ShowDialog();
			if (!SMA.m_SuccessCreate)
			{
				((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "��ͼ�������ʧ�ܣ�";
				return nullptr;
			}
			IsMark = SMA.m_MarkArguments;
			IsCheck = SMA.m_IsCheck;
			S_region = firstRegion;



			m_drawingRectangle.Width = firstRegion.Width / originalImageWidth * canvas_RectangleContainer.Width;
			m_drawingRectangle.Height = firstRegion.Height / originalImageHeight * canvas_RectangleContainer.Height;
			Canvas.SetLeft(m_drawingRectangle, firstRegion.X / originalImageWidth * canvas_RectangleContainer.Width);
			Canvas.SetTop(m_drawingRectangle, firstRegion.Y / originalImageHeight * canvas_RectangleContainer.Height);
			m_drawingRectangle.Fill = new SolidColorBrush((Color)ColorConverter.ConvertFromString(firstRegion.BackgroundColor));
			m_drawingRectangle.Fill.Opacity = 0.4;
			m_drawingRectangle.Stroke = new SolidColorBrush((Color)ColorConverter.ConvertFromString(firstRegion.BorderColor));
			m_drawingRectangle.StrokeThickness = 1;
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].firstRegion = firstRegion;
			Button_AddMarkRegion.IsEnabled = true;

		}
		if (Keyboard.Modifiers != ModifierKeys.Shift)
			((MainWindow)App.Current.MainWindow).EnableOperationFunction();
		return firstRegion;
	}
	else
	{
		((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "�����ѡʧ�ܣ�";
		region = new FormPattern.MRegion();
		if (Keyboard.Modifiers != ModifierKeys.Shift)
			((MainWindow)App.Current.MainWindow).EnableOperationFunction();
		return nullptr;
	}

}

Cm2::FormPattern::MRegion * Cm2::FormPatternMaker::RegionArgumentBuilder::BuildMarkRegionArgument(QRect & iRect, bool IsContinue)
{
	int x = 0;
	int y = 0;

	//���з�տ�
	vector<Cm2.FormPattern.MRegion[, ]> allRegions = new vector<FormPattern.MRegion[, ]>();


	// ������λ������Ϣ
	Cm2.FormPattern.MRegion regionMarks = new Cm2.FormPattern.MRegion();
	regionMarks.Name = "��Ϳ������-";
	regionMarks.X = (int32_t)Math.Round(iRect.X);
	regionMarks.Y = (int32_t)Math.Round(iRect.Y);
	regionMarks.Width = (int32_t)Math.Round(iRect.Width);
	regionMarks.Height = (int32_t)Math.Round(iRect.Height);
	regionMarks.BorderColor = Colors.Black.ToString();
	regionMarks.BackgroundColor = Colors.Orange.ToString();



	//ʶ�������ڵ����з������
	allRegions.Add(FormPatternMakerHelper[s_CurrentSelectedFormIndex].FindClosedShapesOnRegion(regionMarks, S_region.Width, S_region.Height));
	int32_t indexNum = -1;
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].MarkPattern != nullptr)
	{
		indexNum = (*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].MarkPattern.MarkBlockSet.Count - 1;
	}
	for (int32_t i = 0; i < allRegions.Count; ++i)
	{
		for (int32_t j = 0; j < allRegions[i].GetLength(0); ++j)
		{
			for (int32_t k = 0; k < allRegions[i].GetLength(1); ++k)
			{
				indexNum++;
				if (allRegions[i][j, k] != nullptr)
				{
					allRegions[i][j, k].BackgroundColor = Colors.OrangeRed.ToString();
					allRegions[i][j, k].BorderColor = Colors.Black.ToString();
					//allRegions[i][j, k].Name = "��Ϳ��-" + indexNum;
				}
			}
		}
	}


	((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "����ϸ���ø���Ϳ�����ʶ���������";
	MarkRegionArguments regionArgWnd = new MarkRegionArguments();
	regionArgWnd.Owner = App.Current.MainWindow;
	regionArgWnd.Initial(ref regionMarks, allRegions);
	regionArgWnd.ShowDialog();



	// �ɹ��������������ʾ
	if (regionArgWnd.m_SuccessCreate)
	{
		CreateRegionTreeViewItem(EnumSet.RecognizeType.Mark, regionMarks);

		if (Keyboard.Modifiers != ModifierKeys.Shift)
			((MainWindow)App.Current.MainWindow).EnableOperationFunction();


		S_lastMarkRegion = allRegions;
		((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "��Ϳ���������ѡ��ɣ��ɼ���������򡭡�";
		regionMarks.BorderColor = nullptr;
		regionMarks.BackgroundColor = nullptr;
		return regionMarks;
	}
	else
	{
		return nullptr;
	}


}

Cm2::FormPattern::MRegion * Cm2::FormPatternMaker::RegionArgumentBuilder::BuildImageshotArgument(QRect & iRect)

{
	// ������ͼ������Ϣ
	Cm2.FormPattern.MRegion region = new Cm2.FormPattern.MRegion();
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].ImageShotPattern != nullptr)
		region.Name = "��ͼ����-" + ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].ImageShotPattern.ShotRegions.Count + 1);
	else
		region.Name = "��ͼ����-1";
	region.X = (int32_t)Math.Round(iRect.X);
	region.Y = (int32_t)Math.Round(iRect.Y);
	region.Width = (int32_t)Math.Round(iRect.Width);
	region.Height = (int32_t)Math.Round(iRect.Height);
	region.BorderColor = Colors.Black.ToString();
	region.BackgroundColor = Colors.Red.ToString();
	Boolean IsAlwaysShotImage = false;

	((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "��ͼ�����ѡ�����";
	ImageShotRegionArguments regionArgWnd = new ImageShotRegionArguments();
	regionArgWnd.Owner = App.Current.MainWindow;
	regionArgWnd.Initial(ref region, ref IsAlwaysShotImage);
	regionArgWnd.ShowDialog();

	if (!regionArgWnd.m_SuccessCreate)
	{
		((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "��ͼ�������ʧ�ܣ�";
		return nullptr;
	}

	// �ɹ��������������ʾ

	(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].ImageShotPattern.ShotRegions.Add(region);
	CreateRegionTreeViewItem(EnumSet.RecognizeType.ImageShot, region);

	if (Keyboard.Modifiers != ModifierKeys.Shift)
		((MainWindow)App.Current.MainWindow).EnableOperationFunction();
	return region;
}

Cm2::FormPattern::MRegion * Cm2::FormPatternMaker::RegionArgumentBuilder::BuildOCRArgument(QRect & iRect)

{
	// ����OCR������Ϣ
	Cm2.FormPattern.MRegion region = new Cm2.FormPattern.MRegion();
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].OCRPattern != nullptr)
		region.Name = "�ַ�����-" + ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].OCRPattern.OCRRegions.Count + 1);
	else
		region.Name = "�ַ�����-1";
	region.X = (int32_t)Math.Round(iRect.X);
	region.Y = (int32_t)Math.Round(iRect.Y);
	region.Width = (int32_t)Math.Round(iRect.Width);
	region.Height = (int32_t)Math.Round(iRect.Height);
	region.BorderColor = Colors.Black.ToString();
	region.BackgroundColor = Colors.Purple.ToString();

	//CasitMark.PlatformInstance.PlatformAccess.GetImageProcessObject().SaveThePartOfImage(
	//    CasitMarkPatternManager.s_CurrentPattern.FormPatterns[CasitMarkPatternManager.s_CurrentSelectedFormIndex].TemplateImageData,
	//    System.Windows.Forms.Application.StartupPath + "\\OCRRegionImage.jpg", region.RegionArea);

	((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "�ַ�ʶ�������ѡ�����";
	OCRRegionArguments regionArgWnd = new OCRRegionArguments();
	regionArgWnd.Owner = App.Current.MainWindow;
	regionArgWnd.Initial(ref region, s_CurrentSelectedFormIndex);
	regionArgWnd.ShowDialog();

	if (!regionArgWnd.m_SuccessCreate)
		return nullptr;

	// �ɹ��������������ʾ
	(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].OCRPattern.OCRRegions.Add(region);
	CreateRegionTreeViewItem(EnumSet.RecognizeType.OCR, region);
	if (Keyboard.Modifiers != ModifierKeys.Shift)
		((MainWindow)App.Current.MainWindow).EnableOperationFunction();
	((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "�ַ�ʶ�������ѡ��ɣ��ɼ���������򡭡�";
	return region;
}

Cm2::FormPattern::MRegion * Cm2::FormPatternMaker::RegionArgumentBuilder::BuildBarOr2DCodeArgument(QRect & iRect)
{
	// ��������������Ϣ
	Cm2.FormPattern.MRegion region = new Cm2.FormPattern.MRegion();
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].BarcodePattern != nullptr)
		region.Name = "�������ά������-" + ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].BarcodePattern.BarCodeSearchRegions.Count + 1);
	else
		region.Name = "�������ά������-1";
	region.X = (int32_t)Math.Round(iRect.X);
	region.Y = (int32_t)Math.Round(iRect.Y);
	region.Width = (int32_t)Math.Round(iRect.Width);
	region.Height = (int32_t)Math.Round(iRect.Height);
	region.BorderColor = Colors.Black.ToString();
	region.BackgroundColor = Colors.LawnGreen.ToString();

	Cm2.FormPattern.MBarCodeType BarCodeTypes = new FormPattern.MBarCodeType();
	BarCodeTypes = FormPatternMakerHelper[s_CurrentSelectedFormIndex].MultipleBarCodeRecognizeOnRegion(region, ref barCodeValue);
	int index = s_CurrentSelectedFormIndex;
	((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "������ά�������ѡ�����";
	BarCodeRegionArguments regionArgWnd = new BarCodeRegionArguments();
	regionArgWnd.Owner = App.Current.MainWindow;
	regionArgWnd.Initial(ref region, BarCodeTypes, barCodeValue, index);
	regionArgWnd.ShowDialog();

	if (!regionArgWnd.m_SuccessCreate)
		return nullptr;

	// �ɹ��������������ʾ
	CreateRegionTreeViewItem(EnumSet.RecognizeType.BarOr2DCode, region);
	if (Keyboard.Modifiers != ModifierKeys.Shift)
		((MainWindow)App.Current.MainWindow).EnableOperationFunction();

	((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "������ά�������ѡ��ɣ��ɼ���������򡭡�";
	return region;
}

Cm2::FormPattern::MRegion * Cm2::FormPatternMaker::RegionArgumentBuilder::BuildSevenArgument(QRect & iRect)
{
	// ������λ������Ϣ
	Cm2.FormPattern.MRegion region = new Cm2.FormPattern.MRegion();
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SevenSectionPattern != nullptr)
		region.Name = "�߶�������-" + ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SevenSectionPattern.SevenSections.Count + 1);
	else
		region.Name = "�߶�������-1";
	region.X = (int32_t)Math.Round(iRect.X);
	region.Y = (int32_t)Math.Round(iRect.Y);
	region.Width = (int32_t)Math.Round(iRect.Width);
	region.Height = (int32_t)Math.Round(iRect.Height);
	region.BorderColor = Colors.Black.ToString();
	region.BackgroundColor = Colors.Yellow.ToString();

	//int sevenNum = -1;
	//vector<Cm2.FormPattern.MRegion> regions = FormPatternMakerHelper[s_CurrentSelectedFormIndex].SevenSegment(region);
	//vector<int> sevenNums = new vector<int>();
	//for (int i = 0; i < regions.Count; ++i)
	//{
	//    Byte[] image = FormPatternMakerHelper[s_CurrentSelectedFormIndex].GetRectImg(regions[i]);
	//    sevenNum = FormPatternMakerHelper[s_CurrentSelectedFormIndex].SevenSegmentRecognizeOnRegion(image);
	//    sevenNums.Add(sevenNum);
	//}

	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SevenSectionPattern == nullptr)
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SevenSectionPattern = new FormPattern.MSevenSectionPattern();
	(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SevenSectionPattern.SevenSections.Add(region);

	CreateRegionTreeViewItem(EnumSet.RecognizeType.Seven, region);
	if (Keyboard.Modifiers != ModifierKeys.Shift)
		((MainWindow)App.Current.MainWindow).EnableOperationFunction();

	((MainWindow)App.Current.MainWindow).L_ShowTipMessage.Content = "�߶��������ѡ��ɣ��ɼ���������򡭡�";
	return region;

}

Cm2::FormPattern::MRegion * Cm2::FormPatternMaker::RegionArgumentBuilder::BuildSycnArgument(QRect & iRect, bool iRemoveOldNode)
{
	Cm2.FormPattern.MRegion Lregion = new Cm2.FormPattern.MRegion();
	Cm2.FormPattern.MRegion Rregion = new Cm2.FormPattern.MRegion();
	indexSycn++;
	vector<Cm2.FormPattern.MRegion> LeftSyncRows = new vector<FormPattern.MRegion>();
	vector<Cm2.FormPattern.MRegion> RightSyncRows = new vector<FormPattern.MRegion>();
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern == nullptr)
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern = new FormPattern.MSyncRowPattern();
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRowSearchArea == nullptr)
	{
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRowSearchArea = Lregion;
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.RightSyncRowSearchArea = Rregion;
	}
	else
	{
		(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.RightSyncRowSearchArea = Rregion;
	}
	if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRowSearchArea.Name == "")
	{
		Lregion.Name = "��ͬ����";
		Lregion.X = (int32_t)Math.Round(iRect.X);
		Lregion.Y = (int32_t)Math.Round(iRect.Y);
		Lregion.Width = (int32_t)Math.Round(iRect.Width);
		Lregion.Height = (int32_t)Math.Round(iRect.Height);
		Lregion.BorderColor = Colors.Black.ToString();
		Lregion.BackgroundColor = Colors.DarkGray.ToString();
	}
	else
	{
		if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRowSearchArea.Name == "��ͬ����")
		{
			Rregion.Name = "��ͬ����";
			Rregion.X = (int32_t)Math.Round(iRect.X);
			Rregion.Y = (int32_t)Math.Round(iRect.Y);
			Rregion.Width = (int32_t)Math.Round(iRect.Width);
			Rregion.Height = (int32_t)Math.Round(iRect.Height);
			Rregion.BorderColor = Colors.Black.ToString();
			Rregion.BackgroundColor = Colors.DarkGray.ToString();
		}
		else
		{
			Lregion.Name = "��ͬ����";
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRowSearchArea.Name = "��ͬ����";
			Lregion.X = (int32_t)Math.Round(iRect.X);
			Lregion.Y = (int32_t)Math.Round(iRect.Y);
			Lregion.Width = (int32_t)Math.Round(iRect.Width);
			Lregion.Height = (int32_t)Math.Round(iRect.Height);
			Lregion.BorderColor = Colors.Black.ToString();
			Lregion.BackgroundColor = Colors.DarkGray.ToString();
		}
	}



	if (Lregion.Name == "��ͬ����")
	{
		LeftSyncRows = FormPatternMakerHelper[s_CurrentSelectedFormIndex].SyncSearchOnRegion(Lregion);
		if (LeftSyncRows != nullptr)
		{
			if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.RightSyncRows != nullptr)
			{
				if (LeftSyncRows.Count == (*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.RightSyncRows.Count)
				{
					if (SelfDefineUC.MetroStyleMessageBox.ShowMessageBox_OkCancel(nullptr, "�Ƿ񱣴浱ǰ��ͬ����ʶ������", "Help"))
					{
						(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRowSearchArea = Lregion;
						(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRows = LeftSyncRows;
						CreateRegionTreeViewItem(EnumSet.RecognizeType.SyncRow, Lregion);
						return Lregion;

					}
					else
					{
						(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern = nullptr;
						return nullptr;
					}
				}
				else
				{
					SelfDefineUC.MetroStyleMessageBox.ShowMessageBox_Ok(nullptr, "����ͬ������Ŀ���ȣ������¿�ѡ��", "Information");
					return nullptr;
				}
			}
			else
			{
				if (SelfDefineUC.MetroStyleMessageBox.ShowMessageBox_OkCancel(nullptr, "�Ƿ񱣴浱ǰ��ͬ����ʶ������", "Help"))
				{
					(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRowSearchArea = Lregion;
					(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRows = LeftSyncRows;
					CreateRegionTreeViewItem(EnumSet.RecognizeType.SyncRow, Lregion);
					return Lregion;

				}
				else
				{
					(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern = nullptr;
					return nullptr;
				}
			}
		}
		else
		{
			return nullptr;
		}

	}
	else
	{
		RightSyncRows = FormPatternMakerHelper[s_CurrentSelectedFormIndex].SyncSearchOnRegion(Rregion);
		if (RightSyncRows != nullptr)
		{
			if ((*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRows != nullptr)
			{
				if (RightSyncRows.Count == (*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.LeftSyncRows.Count)
				{
					if (SelfDefineUC.MetroStyleMessageBox.ShowMessageBox_OkCancel(nullptr, "�Ƿ񱣴浱ǰ��ͬ����ʶ������", "Help"))
					{
						(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.RightSyncRowSearchArea = Rregion;
						(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.RightSyncRows = RightSyncRows;
						CreateRegionTreeViewItem(EnumSet.RecognizeType.SyncRow, Rregion);
						if (Keyboard.Modifiers != ModifierKeys.Shift)
							((MainWindow)App.Current.MainWindow).EnableOperationFunction();
						return Rregion;
					}
					else
					{
						(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern = nullptr;
						return nullptr;
					}
				}
				else
				{
					SelfDefineUC.MetroStyleMessageBox.ShowMessageBox_Ok(nullptr, "����ͬ������Ŀ���ȣ������¿�ѡ��", "Information");
					return nullptr;
				}

			}
			else
			{
				if (SelfDefineUC.MetroStyleMessageBox.ShowMessageBox_OkCancel(nullptr, "�Ƿ񱣴浱ǰ��ͬ����ʶ������", "Help"))
				{
					(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.RightSyncRowSearchArea = Rregion;
					(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern.RightSyncRows = RightSyncRows;
					CreateRegionTreeViewItem(EnumSet.RecognizeType.SyncRow, Rregion);
					if (Keyboard.Modifiers != ModifierKeys.Shift)
						((MainWindow)App.Current.MainWindow).EnableOperationFunction();
					return Rregion;
				}
				else
				{
					(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern = nullptr;
					return nullptr;
				}
			}

		}
		else
		{
			(*_CurrentEditPattern->FormPatterns)[s_CurrentSelectedFormIndex].SyncRowPattern = nullptr;
			return nullptr;
		}
	}
}

void Cm2::FormPatternMaker::RegionArgumentBuilder::DeleteFormChangeMatrix(const string & iPatternGUID, const int32_t & iFormIndex)
{
	if (!s_allChangeMatrix.Contains(iPatternGUID))
		return;
	Hashtable table = s_allChangeMatrix[iPatternGUID] as Hashtable;
	if (!table.Contains(iFormIndex))
		return;
	table.Remove(iFormIndex);
}

void Cm2::FormPatternMaker::RegionArgumentBuilder::DeletePatternMatrix(const string & iPatternGUID)
{
	s_allChangeMatrix->erase(iPatternGUID);
}


*/