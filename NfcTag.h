#ifndef NfcTag_h
#define NfcTag_h

#include <inttypes.h>
#include <Arduino.h>
#include <NdefMessage.h>

class NfcTag
{
    public:
        NfcTag();
        NfcTag(byte *uid, uint32_t uidLength);
        NfcTag(byte *uid, uint32_t uidLength, String tagType);
        NfcTag(byte *uid, uint32_t uidLength, String tagType, NdefMessage& ndefMessage);
        NfcTag(byte *uid, uint32_t uidLength, String tagType, const byte *ndefData, const int ndefDataLength);
        ~NfcTag(void);
        NfcTag& operator=(const NfcTag& rhs);
        uint8_t getUidLength();
        void getUid(byte *uid, uint32_t uidLength);
        String getUidString();
        String getTagType();
        boolean hasNdefMessage();
        NdefMessage getNdefMessage();
        void print();
    private:
        byte *_uid;
        uint32_t _uidLength;
        String _tagType; // Mifare Classic, NFC Forum Type {1,2,3,4}, Unknown
        NdefMessage* _ndefMessage;
        // TODO capacity
        // TODO isFormatted
};

#endif