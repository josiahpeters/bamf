#pragma once

#include <IL/il.h>
#include <map>

#include "gEntitySystem.h"
#include "gEntity.h"
#include "gComponent.h"
#include "gRenderSystem.h"
#include "gVertexComponent.h"
#include "OpenGLUserControl.h"

#include "Vector3.h"
#include "Entity.h"
#include "Cube.h"

namespace Editor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace BAMF;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		gRenderSystem* RenderSystem;
		gEntitySystem* EntitySystem;
		gEntity* test;
		OpenGLUserControl^ OpenGL;
		array<Vector3^>^ vertices;
		gCameraComponent* camera;

		int mouseStartX;
		int mouseStartY;

		int mousePreviousX;
		int mousePreviousY;

		int entityIndex;
		int componentIndex;

		Entity^ selectedEntity;

	private: 

	private: System::Windows::Forms::PropertyGrid^  propertyGrid1;
	private: System::Windows::Forms::Timer^  renderTimer;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  displayModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  solidToolStripMenuItem1;

	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::Windows::Forms::ImageList^  treeImageList;
	private: System::Windows::Forms::ToolStrip^  toolStrip2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  tsAddMesh;
	private: System::Windows::Forms::ToolStripButton^  tsAddTransform;

	private: System::Windows::Forms::ToolStripButton^  tsAddCube;
	private: System::Windows::Forms::ToolStripButton^  tsDeleteComponent;








	private: System::Windows::Forms::ToolStripMenuItem^  wireframeToolStripMenuItem1;








			 
		

	public:
		Form1(void)
		{
			
			InitializeComponent();

			OpenGL = gcnew OpenGLUserControl();
			this->OpenGL->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::opengl_MouseDown);
			this->OpenGL->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::opengl_MouseMove);
			this->OpenGL->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::opengl_MouseUp);
			this->OpenGL->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::opengl_KeyDown);
			this->OpenGL->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::opengl_KeyUp);
			
			splitContainer1->Panel2->Controls->Add(OpenGL);
			OpenGL->Dock = System::Windows::Forms::DockStyle::Fill;

			EntitySystem = new gEntitySystem();
			RenderSystem = new gRenderSystem(EntitySystem);

			test = EntitySystem->CreateEntity();

			mousePreviousX = OpenGL->Width / 2;
			mousePreviousY = OpenGL->Height / 2;

			entityIndex = 0;
			componentIndex = 0;

			selectedEntity = gcnew Entity();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"Entities"));
			System::Windows::Forms::TreeNode^  treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"Map", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) {treeNode1}));
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->propertyGrid1 = (gcnew System::Windows::Forms::PropertyGrid());
			this->renderTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->treeImageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsAddTransform = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsAddMesh = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsAddCube = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->displayModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->solidToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wireframeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsDeleteComponent = (gcnew System::Windows::Forms::ToolStripButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->toolStrip2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// propertyGrid1
			// 
			this->propertyGrid1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->propertyGrid1->Location = System::Drawing::Point(0, 0);
			this->propertyGrid1->Name = L"propertyGrid1";
			this->propertyGrid1->Size = System::Drawing::Size(278, 223);
			this->propertyGrid1->TabIndex = 1;
			// 
			// renderTimer
			// 
			this->renderTimer->Interval = 33;
			this->renderTimer->Tick += gcnew System::EventHandler(this, &Form1::renderTimer_Tick);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(848, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"Add Mesh";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 506);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(848, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// splitContainer1
			// 
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 49);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(848, 457);
			this->splitContainer1->SplitterDistance = 282;
			this->splitContainer1->TabIndex = 4;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->treeView1);
			this->splitContainer2->Panel1->Controls->Add(this->toolStrip2);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->propertyGrid1);
			this->splitContainer2->Size = System::Drawing::Size(278, 453);
			this->splitContainer2->SplitterDistance = 226;
			this->splitContainer2->TabIndex = 2;
			// 
			// treeView1
			// 
			this->treeView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeView1->ImageIndex = 0;
			this->treeView1->ImageList = this->treeImageList;
			this->treeView1->Location = System::Drawing::Point(0, 25);
			this->treeView1->Name = L"treeView1";
			treeNode1->ImageIndex = 1;
			treeNode1->Name = L"entityNode";
			treeNode1->SelectedImageKey = L"rubyblue.png";
			treeNode1->Text = L"Entities";
			treeNode2->Name = L"mapNode";
			treeNode2->Text = L"Map";
			this->treeView1->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) {treeNode2});
			this->treeView1->SelectedImageIndex = 0;
			this->treeView1->Size = System::Drawing::Size(278, 201);
			this->treeView1->TabIndex = 0;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterSelect);
			// 
			// treeImageList
			// 
			this->treeImageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"treeImageList.ImageStream")));
			this->treeImageList->TransparentColor = System::Drawing::Color::Transparent;
			this->treeImageList->Images->SetKeyName(0, L"map.png");
			this->treeImageList->Images->SetKeyName(1, L"rubyblue.png");
			this->treeImageList->Images->SetKeyName(2, L"ruby.png");
			this->treeImageList->Images->SetKeyName(3, L"brick.png");
			this->treeImageList->Images->SetKeyName(4, L"world.png");
			this->treeImageList->Images->SetKeyName(5, L"cog.png");
			this->treeImageList->Images->SetKeyName(6, L"shape_square.png");
			this->treeImageList->Images->SetKeyName(7, L"user.png");
			// 
			// toolStrip2
			// 
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->toolStripButton1, 
				this->toolStripSeparator1, this->tsAddTransform, this->tsAddMesh, this->tsAddCube, this->tsDeleteComponent});
			this->toolStrip2->Location = System::Drawing::Point(0, 0);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(278, 25);
			this->toolStrip2->TabIndex = 0;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click_1);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// tsAddTransform
			// 
			this->tsAddTransform->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsAddTransform->Enabled = false;
			this->tsAddTransform->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tsAddTransform.Image")));
			this->tsAddTransform->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsAddTransform->Name = L"tsAddTransform";
			this->tsAddTransform->Size = System::Drawing::Size(23, 22);
			this->tsAddTransform->Text = L"Add Transform Component";
			this->tsAddTransform->Click += gcnew System::EventHandler(this, &Form1::tsAddTransform_Click);
			// 
			// tsAddMesh
			// 
			this->tsAddMesh->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsAddMesh->Enabled = false;
			this->tsAddMesh->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tsAddMesh.Image")));
			this->tsAddMesh->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsAddMesh->Name = L"tsAddMesh";
			this->tsAddMesh->Size = System::Drawing::Size(23, 22);
			this->tsAddMesh->Text = L"Add Mesh Component";
			// 
			// tsAddCube
			// 
			this->tsAddCube->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsAddCube->Enabled = false;
			this->tsAddCube->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tsAddCube.Image")));
			this->tsAddCube->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsAddCube->Name = L"tsAddCube";
			this->tsAddCube->Size = System::Drawing::Size(23, 22);
			this->tsAddCube->Text = L"Add Cube Component";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->viewToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(848, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->displayModeToolStripMenuItem});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// displayModeToolStripMenuItem
			// 
			this->displayModeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->solidToolStripMenuItem1, 
				this->wireframeToolStripMenuItem1});
			this->displayModeToolStripMenuItem->Name = L"displayModeToolStripMenuItem";
			this->displayModeToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->displayModeToolStripMenuItem->Text = L"Display Mode";
			// 
			// solidToolStripMenuItem1
			// 
			this->solidToolStripMenuItem1->Checked = true;
			this->solidToolStripMenuItem1->CheckOnClick = true;
			this->solidToolStripMenuItem1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->solidToolStripMenuItem1->Name = L"solidToolStripMenuItem1";
			this->solidToolStripMenuItem1->Size = System::Drawing::Size(129, 22);
			this->solidToolStripMenuItem1->Text = L"Solid";
			this->solidToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::solidToolStripMenuItem1_Click);
			// 
			// wireframeToolStripMenuItem1
			// 
			this->wireframeToolStripMenuItem1->CheckOnClick = true;
			this->wireframeToolStripMenuItem1->Name = L"wireframeToolStripMenuItem1";
			this->wireframeToolStripMenuItem1->Size = System::Drawing::Size(129, 22);
			this->wireframeToolStripMenuItem1->Text = L"Wireframe";
			this->wireframeToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::wireframeToolStripMenuItem1_Click);
			// 
			// tsDeleteComponent
			// 
			this->tsDeleteComponent->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsDeleteComponent->Enabled = false;
			this->tsDeleteComponent->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tsDeleteComponent.Image")));
			this->tsDeleteComponent->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsDeleteComponent->Name = L"tsDeleteComponent";
			this->tsDeleteComponent->Size = System::Drawing::Size(23, 22);
			this->tsDeleteComponent->Text = L"toolStripButton2";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(848, 528);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		// terrain
		gVertexComponent* terrain = new gVertexComponent();

		terrain->mesh = gGraphicsFactory::CreateHeightMap(10, 10, NULL, 1, 1);
		terrain->mesh->CreateVBO();

		EntitySystem->AddComponent(test, terrain);
		
		// box
		gEntity* rectEntity = EntitySystem->CreateEntity();

		gVertexComponent* rectVert = new gVertexComponent();
		rectVert->mesh = new gMesh();
		gGraphicsFactory::CreateBox(rectVert->mesh, 1,1,1, vec3(.3, .7, .4));
		rectVert->mesh->CreateVBO();

		EntitySystem->AddComponent(rectEntity, rectVert);

		// init / camera
		bool initialized = OpenGL->GlInitialized;

		camera = new gCameraComponent();
		EntitySystem->AddComponent(test, camera);

		RenderSystem->LoadShader();
		renderTimer->Enabled = true;
	}
	private: System::Void renderTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		float duration = (float)renderTimer->Interval / 1000;
		EntitySystem->Update(duration);
		camera->UpdateMovement(duration);
		OpenGL->Swap();
	}
	
	private: System::Void wireframeToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		RenderSystem->SetRendermode(RenderMode::Wireframe);
		solidToolStripMenuItem1->Checked = false;
	}
	private: System::Void solidToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		RenderSystem->SetRendermode(RenderMode::Solid);
		wireframeToolStripMenuItem1->Checked = false;
	}

	private: System::Void opengl_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		if(e->Button == ::MouseButtons::Right)
		{
			::Cursor::Hide();

			mouseStartX = ::Cursor::Position.X;
			mouseStartY = ::Cursor::Position.Y;	

			mousePreviousX = ::Cursor::Position.X;
			mousePreviousY = ::Cursor::Position.Y;
		}
	}
	private: System::Void opengl_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		if(e->Button == ::MouseButtons::Right)
		{
			int x = ::Cursor::Position.X - mousePreviousX;
			int y = ::Cursor::Position.Y - mousePreviousY;

			mousePreviousX = ::Cursor::Position.X;
			mousePreviousY = ::Cursor::Position.Y;				 				 

			float vertMouseSensitivity  = 0.017;
			float horizMouseSensitivity = 0.017;

			camera->rotationX += (float)x * horizMouseSensitivity;
			camera->rotationY += (float)y * vertMouseSensitivity;

			if(camera->rotationY < -1.57)
			camera->rotationY = -1.57;
			if(camera->rotationY > 1.57)
			camera->rotationY = 1.57;
		}
	}
	private: System::Void opengl_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		if(e->Button == ::MouseButtons::Right)
		{
			::Cursor::Position = ::System::Drawing::Point(mouseStartX, mouseStartY);
			::Cursor::Show();
		}
	}
	private: System::Void opengl_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch ( e->KeyCode )
		{
		case Keys::Escape:
			Application::Exit();
			break;
		case Keys::ShiftKey:
			camera->faster = true;
			break;
		case Keys::Space:
			camera->up = true;
			break;
		case Keys::W :
			camera->forward = true;
			break;
		case Keys::S :
			camera->backward = true;
			break;
		case Keys::A :
			camera->left = true;
			break;
		case Keys::D :
			camera->right = true;
			break;
		}
	}
	private: System::Void opengl_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch ( e->KeyCode )
		{
		case Keys::Escape:
			Application::Exit();
			break;
		case Keys::ShiftKey:
			camera->faster = false;
			break;
		case Keys::Space:
			camera->up = false;
			break;
		case Keys::W :
			camera->forward = false;
			camera->backward = false;
			break;
		case Keys::S :
			camera->backward = false;
			camera->forward = false;
			break;
		case Keys::A :
			camera->left = false;
			camera->right = false;
			break;
		case Keys::D :
			camera->right = false;
			camera->left = false;
			break;
		}
	}
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) 		 
		 {
			 Cube^ cube = gcnew Cube();

			 TreeNode^ node = gcnew TreeNode("Cube", 1, 1);

			 TreeNode^ root = treeView1->Nodes[0];
			 
			 root->Nodes->Add(node);

			 propertyGrid1->SelectedObject = cube;
		 }
private: System::Void toolStripButton1_Click_1(System::Object^  sender, System::EventArgs^  e) 
		 {
			 TreeNode^ meshNode = treeView1->Nodes->Find("entityNode", true)[0];

			 gEntity* entity = EntitySystem->CreateEntity();

			 //TreeNode^ newNode = meshNode->Nodes->Add(entity->id + "", "New Entity " + entity->id, 2);
			 TreeNode^ newNode = gcnew TreeNode("New Entity " + entity->id, 2, 2);
			 newNode->Name = entity->id + "";
			 meshNode->Nodes->Add(newNode);

			 selectedEntity->SelectEntityAndNode(entity, newNode);
			 propertyGrid1->SelectedObject = selectedEntity;
		 }
private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
		 {
			 TreeNode^ node = e->Node;

			 if(node->Level > 0)
			 {
				 //entity
				 if(node->Parent->Name == "entityNode")
				 {
					 int key = Int32::Parse(node->Name);
					 gEntity* entity = EntitySystem->GetEntity(key);
					 selectedEntity->SelectEntityAndNode(entity, node);
					 propertyGrid1->SelectedObject = selectedEntity;
					 tsAddMesh->Enabled = true;
					 tsAddTransform->Enabled = true;
					 tsAddCube->Enabled = true;
					 tsDeleteComponent->Enabled = true;					 
				 }
				 if(node->Level > 2)
				 {
					 // component ( parent of parent )
					 if(node->Parent->Parent->Name == "entityNode")
					 {
						 if(node->Name == "Transform Component")
						 {

						 }
					 }
				 }
				 
			 }			 
		 }
private: System::Void tsAddTransform_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(selectedEntity->node->Parent->Name == "entityNode")
			 {
				 gTransformComponent* component = new gTransformComponent();
				 EntitySystem->AddComponent(selectedEntity->unmanaged, component);

				 TreeNode^ newNode = gcnew TreeNode("Transform Component", 4, 4);
				 newNode->Name = selectedEntity->unmanaged->id + "";
				 selectedEntity->node->Nodes->Add(newNode);
			 }
		 }
};
}

