//
// Generated file, do not edit! Created by opp_msgc 4.3 from packet/Packet.msg.
//

#ifndef _PACKET_M_H_
#define _PACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0403
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>packet/Packet.msg</tt> by opp_msgc.
 * <pre>
 * packet Packet {
 *     int src;
 *     int dst;
 *     int sessionID;
 *     int packetID;
 *     int priority;
 *     int hops;
 *     int payload;
 *     int ds;
 *     double creationTime;
 * }
 * </pre>
 */
class Packet : public ::cPacket
{
  protected:
    int src_var;
    int dst_var;
    int sessionID_var;
    int packetID_var;
    int priority_var;
    int hops_var;
    int payload_var;
    int ds_var;
    double creationTime_var;

  private:
    void copy(const Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Packet&);

  public:
    Packet(const char *name=NULL, int kind=0);
    Packet(const Packet& other);
    virtual ~Packet();
    Packet& operator=(const Packet& other);
    virtual Packet *dup() const {return new Packet(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSrc() const;
    virtual void setSrc(int src);
    virtual int getDst() const;
    virtual void setDst(int dst);
    virtual int getSessionID() const;
    virtual void setSessionID(int sessionID);
    virtual int getPacketID() const;
    virtual void setPacketID(int packetID);
    virtual int getPriority() const;
    virtual void setPriority(int priority);
    virtual int getHops() const;
    virtual void setHops(int hops);
    virtual int getPayload() const;
    virtual void setPayload(int payload);
    virtual int getDs() const;
    virtual void setDs(int ds);
    virtual double getCreationTime() const;
    virtual void setCreationTime(double creationTime);
};

inline void doPacking(cCommBuffer *b, Packet& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Packet& obj) {obj.parsimUnpack(b);}


#endif // _PACKET_M_H_
