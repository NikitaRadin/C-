#pragma once
#include <ctime>
#include <fstream>
#include "Graph.h"

namespace LaboratoryWork24TheLast {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(300, 529);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввод данных";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 305);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(288, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Сгенерировать граф и построить остов";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(6, 255);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(6, 170);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 220);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(181, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Максимальный вес ребра:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(230, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Максимальная степень вершины:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Количество вершин:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 85);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(6, 390);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 355);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(185, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Время построения остова:";
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 553);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form2";
			this->Text = L"Построение остова (автоматическая генерация)";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		ArrayUndirectedGraph<int, int> *AUG = new ArrayUndirectedGraph<int, int>();
		int Number = Convert::ToInt32(textBox1->Text);
		int MaxSt = Convert::ToInt32(textBox2->Text);
		int MaxWeight = Convert::ToInt32(textBox3->Text);
		try {
			if (Number < 1 || MaxSt < 1) {
				throw std::out_of_range("Out of range");
			}
			AUG->AddVertex(1);
			for (int i = 2; i <= Number; i++) {
				AUG->AddVertex(i);
				for (int j = 1; j <= MaxSt; j++) {
					try {
						AUG->AddEdge(i, rand() % (i - 1) + 1, rand() % MaxWeight + 1);
					}
					catch (std::out_of_range Exception) {
					}
				}
			}
		}
		catch (std::out_of_range Exception) {
		}
		int StartTime = clock();
		ArrayUndirectedGraph<int, int> *MST = AUG->GetMinimalSpanningTree();
		int EndTime = clock();
		textBox4->Text = Convert::ToString(EndTime - StartTime) + " мс";
		std::ofstream File;
		File.open("C:\\Users\\lenovo\\Desktop\\LaboratoryWork2.4TheLast\\LaboratoryWork2.4TheLast\\File.txt");
		File << "Исходный граф имеет вид:\n";
		File << AUG->ArrayGraphToString();
		File << "Остов графа имеет вид:\n";
		File << MST->ArrayGraphToString();
		File.close();
		delete AUG;
		delete MST;
	}
};
}
