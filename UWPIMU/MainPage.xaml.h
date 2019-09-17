//
// MainPage.xaml.h
// MainPage 類別的宣告。
//

#pragma once

#include "MainPage.g.h"

namespace UWPIMU
{
	/// <summary>
	/// 可以在本身使用或巡覽至框架內的空白頁面。
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		Windows::Devices::Sensors::Accelerometer^ accelerometer;
		Windows::Foundation::EventRegistrationToken readingToken;
		void Btn1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ReadingChanged(Windows::Devices::Sensors::Accelerometer^ sender, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs^ e);
		void SetReadingText(Windows::Devices::Sensors::AccelerometerReading^ reading);
		
		void Btn2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
