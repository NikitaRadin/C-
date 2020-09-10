#include "MainForm.h"
#include "Form1.h"
#include "Form2.h"
#include "Form3.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LaboratoryWork24TheLast::MainForm form;
	Application::Run(%form);
}