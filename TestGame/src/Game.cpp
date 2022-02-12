#include "Game.h"
#include "Entity2D.h"
#include "glm/gtc/matrix_transform.hpp"

Game::Game(const char* title, unsigned int width, unsigned int height)
{
	m_Window = new Window(title, width, height);
}

Game::~Game()
{
	delete m_Window;
}


void Game::Init()
{
	
}

void Game::Update()
{
	m_Window->Update();
}

void Game::Render()
{
	glClearColor(0.2f, 0.2f, 0.7f, 1.0f);
	m_Renderer.Clear();
	m_Renderer.Flush2D();
}

void Game::Run()
{

	Init();
	Shader shader("res/shaders/Basic.shader");
	shader.Bind();
	
	float width = 800.0f;
	float height = 800.0f;
	float depth = 1.0f;
	glm::mat4 proj = glm::ortho(0.0f, width, 0.0f, height, -depth, depth);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	
	shader.SetUniformMat4f("ml_matrix", model);
	shader.SetUniformMat4f("vw_matrix", view);
	shader.SetUniformMat4f("pr_matrix", proj);

	Entity2D sprite(glm::vec3(350, 350, 0), glm::vec2(50.0f, 50.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1), shader);
	Entity2D sprite2(glm::vec3(370, 370, 1), glm::vec2(50.0f, 50.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1), shader);
	


	while (!m_Window->Closed())
	{
		m_Renderer.Submit2D(&sprite);
		m_Renderer.Submit2D(&sprite2);

		Update();
		Render();
	}
}