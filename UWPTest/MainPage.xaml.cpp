//
// MainPage.xaml.cpp
// MainPage 類別的實作。
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace UWPTest;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Devices::Sensors;
using namespace Windows::UI::Core;
// 空白頁項目範本已記錄在 https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x404

MainPage::MainPage()
{
	InitializeComponent();
}

void UWPTest::MainPage::Btn2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	accvar->ReadingChanged -= readingToken;
	
}


void UWPTest::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	accvar = Accelerometer::GetDefault(AccelerometerReadingType::Standard);
	readingToken = accvar->ReadingChanged += ref new TypedEventHandler<Accelerometer^, AccelerometerReadingChangedEventArgs^>(this, &UWPTest::MainPage::ReadingChanged);
}
void UWPTest::MainPage::ReadingChanged(Accelerometer^ sender, AccelerometerReadingChangedEventArgs^ e)
{
	Dispatcher->RunAsync(
		CoreDispatcherPriority::Normal,
		ref new DispatchedHandler(
			[this,e]()
			{
				UWPTest::MainPage::SetText(e->Reading);
			},
			CallbackContext::Any
		)
	);
}
void UWPTest::MainPage::SetText(Windows::Devices::Sensors::AccelerometerReading^ reading)
{
	TextBox1->Text = "X: " + reading->AccelerationX.ToString() +
		", Y: " + reading->AccelerationY.ToString() +
		", Z: " + reading->AccelerationZ.ToString();
}
void UWPTest::MainPage::TextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}
