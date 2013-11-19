//
// Generated file, do not edit! Created by opp_msgc 4.3 from packet/Packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Packet_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(Packet);

Packet::Packet(const char *name, int kind) : cPacket(name,kind)
{
    this->src_var = 0;
    this->dst_var = 0;
    this->sessionID_var = 0;
    this->packetID_var = 0;
    this->priority_var = 0;
    this->hops_var = 0;
    this->payload_var = 0;
    this->ds_var = 0;
    this->creationTime_var = 0;
}

Packet::Packet(const Packet& other) : cPacket(other)
{
    copy(other);
}

Packet::~Packet()
{
}

Packet& Packet::operator=(const Packet& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void Packet::copy(const Packet& other)
{
    this->src_var = other.src_var;
    this->dst_var = other.dst_var;
    this->sessionID_var = other.sessionID_var;
    this->packetID_var = other.packetID_var;
    this->priority_var = other.priority_var;
    this->hops_var = other.hops_var;
    this->payload_var = other.payload_var;
    this->ds_var = other.ds_var;
    this->creationTime_var = other.creationTime_var;
}

void Packet::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->src_var);
    doPacking(b,this->dst_var);
    doPacking(b,this->sessionID_var);
    doPacking(b,this->packetID_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->hops_var);
    doPacking(b,this->payload_var);
    doPacking(b,this->ds_var);
    doPacking(b,this->creationTime_var);
}

void Packet::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->dst_var);
    doUnpacking(b,this->sessionID_var);
    doUnpacking(b,this->packetID_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->hops_var);
    doUnpacking(b,this->payload_var);
    doUnpacking(b,this->ds_var);
    doUnpacking(b,this->creationTime_var);
}

int Packet::getSrc() const
{
    return src_var;
}

void Packet::setSrc(int src)
{
    this->src_var = src;
}

int Packet::getDst() const
{
    return dst_var;
}

void Packet::setDst(int dst)
{
    this->dst_var = dst;
}

int Packet::getSessionID() const
{
    return sessionID_var;
}

void Packet::setSessionID(int sessionID)
{
    this->sessionID_var = sessionID;
}

int Packet::getPacketID() const
{
    return packetID_var;
}

void Packet::setPacketID(int packetID)
{
    this->packetID_var = packetID;
}

int Packet::getPriority() const
{
    return priority_var;
}

void Packet::setPriority(int priority)
{
    this->priority_var = priority;
}

int Packet::getHops() const
{
    return hops_var;
}

void Packet::setHops(int hops)
{
    this->hops_var = hops;
}

int Packet::getPayload() const
{
    return payload_var;
}

void Packet::setPayload(int payload)
{
    this->payload_var = payload;
}

int Packet::getDs() const
{
    return ds_var;
}

void Packet::setDs(int ds)
{
    this->ds_var = ds;
}

double Packet::getCreationTime() const
{
    return creationTime_var;
}

void Packet::setCreationTime(double creationTime)
{
    this->creationTime_var = creationTime;
}

class PacketDescriptor : public cClassDescriptor
{
  public:
    PacketDescriptor();
    virtual ~PacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PacketDescriptor);

PacketDescriptor::PacketDescriptor() : cClassDescriptor("Packet", "cPacket")
{
}

PacketDescriptor::~PacketDescriptor()
{
}

bool PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Packet *>(obj)!=NULL;
}

const char *PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount(object) : 9;
}

unsigned int PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "src",
        "dst",
        "sessionID",
        "packetID",
        "priority",
        "hops",
        "payload",
        "ds",
        "creationTime",
    };
    return (field>=0 && field<9) ? fieldNames[field] : NULL;
}

int PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dst")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sessionID")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetID")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hops")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "payload")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "ds")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+8;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "double",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : NULL;
}

const char *PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrc());
        case 1: return long2string(pp->getDst());
        case 2: return long2string(pp->getSessionID());
        case 3: return long2string(pp->getPacketID());
        case 4: return long2string(pp->getPriority());
        case 5: return long2string(pp->getHops());
        case 6: return long2string(pp->getPayload());
        case 7: return long2string(pp->getDs());
        case 8: return double2string(pp->getCreationTime());
        default: return "";
    }
}

bool PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrc(string2long(value)); return true;
        case 1: pp->setDst(string2long(value)); return true;
        case 2: pp->setSessionID(string2long(value)); return true;
        case 3: pp->setPacketID(string2long(value)); return true;
        case 4: pp->setPriority(string2long(value)); return true;
        case 5: pp->setHops(string2long(value)); return true;
        case 6: pp->setPayload(string2long(value)); return true;
        case 7: pp->setDs(string2long(value)); return true;
        case 8: pp->setCreationTime(string2double(value)); return true;
        default: return false;
    }
}

const char *PacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<9) ? fieldStructNames[field] : NULL;
}

void *PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Packet *pp = (Packet *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


