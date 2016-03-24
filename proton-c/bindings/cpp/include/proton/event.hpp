#ifndef PROTON_CPP_EVENT_H
#define PROTON_CPP_EVENT_H

/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

#include <proton/export.hpp>
#include <proton/link.hpp>
#include <proton/connection.hpp>
#include <proton/message.hpp>
#include <vector>
#include <string>

namespace proton {

class handler;
class container;
class connection;

/// A context for a proton event.
///
/// @see proton::handler
class event {
  public:
    virtual PN_CPP_EXTERN ~event() {}

    /// @cond INTERNAL
    /// XXX Perhaps remove
    /// Return the name of the event type.
    virtual PN_CPP_EXTERN std::string name() const = 0;
    /// @endcond

    /// Get transport.
    ///
    /// @throw proton::error if this event was not generated by a
    /// transport
    virtual PN_CPP_EXTERN class transport transport() const = 0;

    /// Get connection.
    ///
    /// @throw proton::error if this event was not generated by a
    /// conection
    virtual PN_CPP_EXTERN class connection connection() const = 0;

    /// Get session.
    ///
    /// @throw proton::error if this event was not generated by a
    /// session
    virtual PN_CPP_EXTERN class session session() const = 0;

    /// Get sender.
    ///
    /// @throw proton::error if no sender
    virtual PN_CPP_EXTERN class sender sender() const = 0;

    /// Get receiver.
    ///
    /// @throw proton::error if no receiver
    virtual PN_CPP_EXTERN class receiver receiver() const = 0;

    /// Get link.
    ///
    /// @throw proton::error if no link
    virtual PN_CPP_EXTERN class link link() const = 0;

    /// Get delivery.
    ///
    /// @throw proton::error if no delivery
    virtual PN_CPP_EXTERN class delivery delivery() const = 0;

    // XXX Should we have a notion of application data?  Perhaps this
    // is relevant to timer and app events.
};

}

#endif // PROTON_CPP_EVENT_H
