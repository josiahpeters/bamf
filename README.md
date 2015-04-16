# BAMF - Bear Arms Militia Force

The project consists of a simple Entity System Engine written as a C++ library and a Managed C++/CLI .NET Windows Form application that will serve as a scene editor. The editor uses the C++ library as an engine to render the current scene.

## Engine

The engine is a [entity component system](http://en.wikipedia.org/wiki/Entity_component_system).

## Editor
The editor was created as a way to run the engine and provide a mechanism for adding, editing, and inspecting objects within the engine. I don't exactly remember how far I progressed on it.

Example Code
Form1.h

## Build
You should be able to load the /src/BAMF.sln solution in Visual Studio 2013 and build the solution. Once built, look in /src/Debug/ and run Editor.exe to launch the basic editor.

### Controls
Use **WASD** to move the camera. Hold **Right Click** and move your mouse to move the camera around.

You can go into view and toggle between wireframe and rendered mode.

## Example Engine Useage
In [/src/Editor/Form1.h](/src/Editor/Form1.h) the Form1_Load method:

```cpp
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
```