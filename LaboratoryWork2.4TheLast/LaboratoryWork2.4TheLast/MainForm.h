#pragma once
#include "Form1.h"
#include "Form2.h"
#include "Form3.h"

namespace LaboratoryWork24TheLast {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  постороитьОстовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  запуститьТестыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  запускТестовToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->постороитьОстовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->запуститьТестыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->запускТестовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->постороитьОстовToolStripMenuItem,
					this->запуститьТестыToolStripMenuItem, this->запускТестовToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(982, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// постороитьОстовToolStripMenuItem
			// 
			this->постороитьОстовToolStripMenuItem->Name = L"постороитьОстовToolStripMenuItem";
			this->постороитьОстовToolStripMenuItem->Size = System::Drawing::Size(268, 24);
			this->постороитьОстовToolStripMenuItem->Text = L"Постороение остова (ручной ввод)";
			this->постороитьОстовToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::постороитьОстовToolStripMenuItem_Click);
			// 
			// запуститьТестыToolStripMenuItem
			// 
			this->запуститьТестыToolStripMenuItem->Name = L"запуститьТестыToolStripMenuItem";
			this->запуститьТестыToolStripMenuItem->Size = System::Drawing::Size(360, 24);
			this->запуститьТестыToolStripMenuItem->Text = L"Построение остова (автоматическая генерация)";
			this->запуститьТестыToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::запуститьТестыToolStripMenuItem_Click);
			// 
			// запускТестовToolStripMenuItem
			// 
			this->запускТестовToolStripMenuItem->Name = L"запускТестовToolStripMenuItem";
			this->запускТестовToolStripMenuItem->Size = System::Drawing::Size(115, 24);
			this->запускТестовToolStripMenuItem->Text = L"Запуск тестов";
			this->запускТестовToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::запускТестовToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(958, 510);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 553);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Главное меню";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void постороитьОстовToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Form1 ^Form10 = gcnew Form1();
		Form10->Show();
	}
	private: System::Void запуститьТестыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Form2 ^Form20 = gcnew Form2();
		Form20->Show();
	}
	private: System::Void запускТестовToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Form3 ^Form30 = gcnew Form3();
		Form30->Show();
	}
};
}
