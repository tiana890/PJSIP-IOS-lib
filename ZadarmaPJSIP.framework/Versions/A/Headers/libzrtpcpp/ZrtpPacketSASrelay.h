/*
 * Copyright 2006 - 2018, Werner Dittmann
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _ZRTPPACKETSASRELAY_H_
#define _ZRTPPACKETSASRELAY_H_

/**
 * @file ZrtpPacketSASrelay.h
 * @brief The ZRTP SAS Relay message
 *
 * @ingroup GNU_ZRTP
 * @{
 */

#include <ZadarmaPJSIP/libzrtpcpp/ZrtpPacketBase.h>

/**
 * Implement the Confirm packet.
 *
 * The ZRTP message Confirm. The implementation sends this
 * to confirm the switch to SRTP (encrypted) mode. The contents of
 * the Confirm message are encrypted, thus the implementation
 * can check if the secret keys work.
 *
 * @author Werner Dittmann <Werner.Dittmann@t-online.de>
 */

class __EXPORT ZrtpPacketSASrelay : public ZrtpPacketBase {

    private:
        SASrelay_t* sasRelayHeader;   ///< Point to the Confirm message part

    public:
        /// Creates a Confirm packet with default data
        ZrtpPacketSASrelay();

        /// Creates a Confirm packet with default data and a given signature length
        ZrtpPacketSASrelay(uint32_t sl);

        /// Creates a Confirm packet from received data
        ZrtpPacketSASrelay(uint8_t* d);

        /// Normal destructor
        virtual ~ZrtpPacketSASrelay();

        /// Check is SAS verify flag is set
        const bool isSASFlag()            { return (sasRelayHeader->flags & 0x4) == 0x4 ? true : false; }

        /// Get pointer to filler bytes (contains one bit of signature length)
        const uint8_t* getFiller()        { return sasRelayHeader->filler; }

        /// Get pointer to IV data, fixed byte array
        const uint8_t* getIv()            { return sasRelayHeader->iv; }

        /// Get pointer to MAC data, fixed byte array
        const uint8_t* getHmac()          { return sasRelayHeader->hmac; }

        /// Get pointer to new SAS rendering algorithm, fixed byte array
        const uint8_t* getSasAlgo() {return sasRelayHeader->sas; }

        /// Get pointer to new SAS hash data, fixed byte array
        const uint8_t* getTrustedSas()    { return sasRelayHeader->trustedSasHash; }

        /// get the signature length in words
        uint32_t getSignatureLength();

        /// Check if packet length makes sense. SAS rely packets are 19 words at minumum, they are similar to Confirm
        bool isLengthOk()                 {return (getLength() >= 19);}

        /// set SAS verified flag
        void setSASFlag()            { sasRelayHeader->flags |= 0x4; }

        /// Set MAC data, fixed length byte array
        void setHmac(uint8_t* text)  { memcpy(sasRelayHeader->hmac, text, sizeof(sasRelayHeader->hmac)); }

        /// Set IV data, fixed length byte array
        void setIv(uint8_t* text)    { memcpy(sasRelayHeader->iv, text, sizeof(sasRelayHeader->iv)); }

        /// Set SAS rendering algorithm, fixed length byte array
        void setSasAlgo(uint8_t* text) { memcpy(sasRelayHeader->sas, text, sizeof(sasRelayHeader->sas)); }

        /// Set SAS hash data, fixed length byte array
        void setTrustedSas(uint8_t* text)    { memcpy(sasRelayHeader->trustedSasHash, text, sizeof(sasRelayHeader->trustedSasHash)); }

        /// Set signature length in words
        void setSignatureLength(uint32_t sl);

    private:
        void initialize();
     // Confirm packet is of variable length. It maximum size is 524 words:
     // - 11 words fixed size
     // - up to 513 words variable part, depending if signature is present and its length.
     // This leads to a maximum of 4*524=2096 bytes.
        uint8_t data[2100];       // large enough to hold a full blown Confirm packet

};

/**
 * @}
 */
#endif // ZRTPPACKETSASRELAY

