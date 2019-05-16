// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef UXR_AGENT_P2P_AGENT_DISCOVERER_HPP_
#define UXR_AGENT_P2P_AGENT_DISCOVERER_HPP_

#include <atomic>
#include <thread>

namespace eprosima {
namespace uxr {

class AgentDiscoverer
{
public:
    AgentDiscoverer();
    ~AgentDiscoverer() = default;

    AgentDiscoverer(AgentDiscoverer&&) = delete;
    AgentDiscoverer(const AgentDiscoverer&) = delete;
    AgentDiscoverer& operator=(AgentDiscoverer&&) = delete;
    AgentDiscoverer& operator=(const AgentDiscoverer&) = delete;

    bool run();
    bool stop();

private:
    void discovery_loop();

private:
    std::atomic<bool> running_cond_;
    std::thread thread_;
};

} // namespace uxr
} // namespace eprosima

#endif // UXR_AGENT_P2P_AGENT_DISCOVERER_HPP_
