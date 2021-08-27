#include "Message.h"
#include <string>

void Message::Load()
{

}

void Message::Init()
{

}

bool Message::Log(const char* message)
{
    if (Messages.size() < MaxMessages)
    {
        MessageFormat messageformat;
        messageformat.Message = message;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(const char* message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        MessageFormat messageformat;
        messageformat.Message = message;
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(const char* message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        MessageFormat messageformat;
        messageformat.Message = message;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(const char* message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        MessageFormat messageformat;
        messageformat.Message = message;
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(int message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(int message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(int message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(int message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(float message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(float message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(float message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(float message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(double message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(double message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(double message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(double message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long double message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long double message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long double message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long double message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned long long message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned long long message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned long long message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned long long message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long long message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long long message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long long message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long long message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned long message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned long message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned long message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned long message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(long message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned int message)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned int message, Colour MessageColour)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned int message, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::Log(unsigned int message, Colour MessageColour, bool StayOnTop)
{
    if (Messages.size() < MaxMessages)
    {
        std::string TextMessage = std::to_string(message);

        MessageFormat messageformat;
        messageformat.Message = TextMessage.c_str();
        messageformat.MessageColour = MessageColour;
        messageformat.StayOnTop = StayOnTop;
        Messages.push_back(messageformat);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Message::LogWarning(const char* message)
{
    if (Messages.size() < MaxMessages)
    {
        WarningMessages.push_back(message);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}


bool Message::LogError(const char* message)
{
    if (Messages.size() < MaxMessages)
    {
        ErrorMessages.push_back(message);
        TotalMessages++;
        return true;
    }
    else
    {
        return false;
    }
}

void Message::ChangeMaxMessageSize(int maxmessages)
{
    MaxMessages = maxmessages;

    if (TotalMessages > MaxMessages)
    {
        if (Messages.size() < MaxMessages)
        {
            Messages.resize(MaxMessages);
        }

        TotalMessages = Messages.size();
        TotalMessages += WarningMessages.size();
        TotalMessages += ErrorMessages.size();

        if (TotalMessages == MaxMessages)
        {
            return;
        }

        while (TotalMessages > MaxMessages)
        {
            if (WarningMessages.size() != 0)
            {
                WarningMessages.pop_back();
                TotalMessages--;
            }
            else
            {
                return;
            }
        }

        if (TotalMessages == MaxMessages)
        {
            return;
        }

        while (TotalMessages > MaxMessages)
        {
            if (ErrorMessages.size() != 0)
            {
                ErrorMessages.pop_back();
                TotalMessages--;
            }
            else
            {
                return;
            }
        }
    }
}

void Message::Clean()
{

}
