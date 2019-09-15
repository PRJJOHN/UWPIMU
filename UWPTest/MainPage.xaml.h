//
// MainPage.xaml.h
// MainPage 類別的宣告。
//

#pragma once

#include "MainPage.g.h"

namespace UWPTest
{
	/// <summary>
	/// 可以在本身使用或巡覽至框架內的空白頁面。
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		Windows::Devices::Sensors::Accelerometer^ accvar;
		Windows::Foundation::EventRegistrationToken readingToken;
		void Btn2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void TextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void ReadingChanged(Windows::Devices::Sensors::Accelerometer^ sender, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs^ e);
		void SetText(Windows::Devices::Sensors::AccelerometerReading^ reading);
	};
}
