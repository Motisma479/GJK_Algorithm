#pragma once

class App
{
private:
	int width_, heigth_;
	bool isInit_;
public:
	App();
	App(const char* name, int width, int height);
	~App();

	void Update();

protected:
	void Init(const char* name, int width, int height);
	void Destroy();

	void StartFrame();
	void EndFrame();
};