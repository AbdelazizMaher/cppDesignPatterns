#include <iostream>
#include "GameActorPool.h"


ActorPtr GameActorPool::createActor(const std::string& actorName)
{
    std::cout << "[POOL]: Creating a new actor of type " << actorName << std::endl;
    ActorPtr actor{};

    if (!m_GameActors[actorName].m_actorCreator)
    {
        std::cout << "[ERROR]: Creator not registered " << std::endl;
        return actor;
    }
    actor = m_GameActors[actorName].m_actorCreator();
    m_GameActors[actorName].m_actorPool.push_back(actor);

    return actor;
}

ActorPtr GameActorPool::findActor(const std::vector<ActorPtr>& actorPool)
{
    auto it = std::find_if(actorPool.begin(), actorPool.end(), [](const ActorPtr& actor) {
        return !actor->getVisible();
        });

    if (it != actorPool.end())
    {
        (*it)->setVisible(true);
        return (*it);
    }
    return nullptr;
}

void GameActorPool::registerCreator(const std::string& actorName, actorCreator creator)
{
    m_GameActors[actorName].m_actorCreator = creator;
}

ActorPtr GameActorPool::aquireActor(const std::string& actorName)
{
    if (auto it = m_GameActors.find(actorName); it == m_GameActors.end())
        return createActor(actorName);

    ActorPtr actor{};

    auto &actorPool = m_GameActors[actorName].m_actorPool;
    actor = findActor(actorPool);
    if (!actor)
        actor = createActor(actorName);
    else
        std::cout << "[POOL]: Returning an existing actor of type " << actorName << std::endl;

    return actor;
}


void GameActorPool::releaseActor(const std::string& actorName, const ActorPtr& releaseActor)
{
    if (auto it = m_GameActors.find(actorName); it == m_GameActors.end())
        throw std::runtime_error("Actor not found");

    auto& actorPool = m_GameActors[actorName].m_actorPool;
    for (auto& actor : actorPool)
    {
        if (actor == releaseActor)
        {
            actor->setVisible(false);
            break;
        }
    }
}
