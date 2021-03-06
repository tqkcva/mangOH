#include "ntagDefs.h"

/* SWI mangOH Yellow has the 2K Ntag */
static Ntag ntag(Ntag::NTAG_I2C_2K,2,5);
static NtagEepromAdapter ntagAdapter(&ntag);

void WriteTagMultipleRecords()
{
    ntagAdapter.begin();
    NdefMessage message = NdefMessage();
    message.addTextRecord("Hello mangOH Yellow!");
    message.addUriRecord("https://mangoh.io/");
    message.addTextRecord("Goodbye mangOH Yellow!");
    if (ntagAdapter.write(message))
    {
        LE_INFO("Success. Try reading this tag with your phone.");
    } else
    {
        LE_INFO("Write failed");
    }
}

