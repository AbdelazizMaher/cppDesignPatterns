#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "GameActor.h"
#include <functional>

using ActorPtr = std::shared_ptr<GameActor>;
using actorCreator = std::function<ActorPtr()>;

class GameActorPool
{
private:
	struct actorInfo
	{
		std::vector<ActorPtr> m_actorPool;
		actorCreator m_actorCreator;
	};

	inline static std::unordered_map<std::string,actorInfo> m_GameActors{};
	GameActorPool() = default;

	static ActorPtr createActor(const std::string& actorName);
	static ActorPtr findActor(const std::vector<ActorPtr>& actorPool);
public:
	static void registerCreator(const std::string& actorName, actorCreator creator);
	static ActorPtr aquireActor(const std::string& actorName);
	static void releaseActor(const std::string& actorName, const ActorPtr& releaseActor);

};

