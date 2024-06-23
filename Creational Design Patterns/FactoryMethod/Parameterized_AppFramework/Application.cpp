#include "Application.h"

void Application::New(const std::string& type)
{
	DocumentFactory factory;
	m_pDocument = factory.Create(type);
}

void Application::Open(const std::string& type)
{
	DocumentFactory factory;
	m_pDocument = factory.Create(type);

	m_pDocument->Read();
}

void Application::Save()
{
	m_pDocument->Write(); 
}
