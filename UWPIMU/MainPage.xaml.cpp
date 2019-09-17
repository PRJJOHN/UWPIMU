//
// MainPage.xaml.cpp
// MainPage 類別的實作。
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace UWPIMU;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Devices::Sensors;
// 空白頁項目範本已記錄在 https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x404

MainPage::MainPage()
{
	InitializeComponent();
}


void UWPIMU::MainPage::Btn1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	accelerometer = Accelerometer::GetDefault(AccelerometerReadingType::Standard);
	readingToken = accelerometer->ReadingChanged += ref new TypedEventHandler<Accelerometer^, AccelerometerReadingChangedEventArgs^>(this, &UWPIMU::MainPage::ReadingChanged);
}
void UWPIMU::MainPage::ReadingChanged(Accelerometer^ sender, AccelerometerReadingChangedEventArgs^ e)
{
	// We need to dispatch to the UI thread to display the output
	Dispatcher->RunAsync(
		CoreDispatcherPriority::Normal,
		ref new DispatchedHandler(
			[this, e]()
			{
				MainPage::SetReadingText(e->Reading);
			},
			CallbackContext::Any
		)
	);
}
void UWPIMU::MainPage::SetReadingText(Windows::Devices::Sensors::AccelerometerReading^ reading)
{
	TextBox1->Text = "X: " + reading->AccelerationX.ToString() +
		", Y: " + reading->AccelerationY.ToString() +
		", Z: " + reading->AccelerationZ.ToString();
}



void UWPIMU::MainPage::Btn2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	accelerometer->ReadingChanged -= readingToken;
}
