/*
 * SCSCL.c
 * 飞特SCSCL系列串行舵机应用层程序
 * 日期: 2018.7.3
 * 作者: 谭雄乐
 */

#include "INST.h"
#include "SCS.h"
#include "SCSCL.h"

int EnableTorque(uint8_t ID, uint8_t Enable)
{
	return writeByte(ID, SCSCL_TORQUE_ENABLE, Enable);
}

int ReadTorqueEnable(uint8_t ID)
{
	return readByte(ID, SCSCL_TORQUE_ENABLE);
}

int writePos(uint8_t ID, uint16_t Position, uint16_t Time, uint16_t Speed, uint8_t Fun)
{
	uint8_t buf[6];
	flushSCS();

	Host2SCS(buf+0, buf+1, Position);
	Host2SCS(buf+2, buf+3, Time);
	Host2SCS(buf+4, buf+5, Speed);
	writeBuf(ID, SCSCL_GOAL_POSITION_L, buf, 6, Fun);
	return Ack(ID);
}

//写位置指令
//舵机ID，Position位置，运行时间Time，速度Speed
int WritePos(uint8_t ID, uint16_t Position, uint16_t Time, uint16_t Speed)
{
	return writePos(ID, Position, Time, Speed, INST_WRITE);
}

//异步写位置指令
//舵机ID，Position位置，运行时间Time，速度Speed
int RegWritePos(uint8_t ID, uint16_t Position, uint16_t Time, uint16_t Speed)
{
	return writePos(ID, Position, Time, Speed, INST_REG_WRITE);
}

void RegWriteAction(void)
{
	writeBuf(0xfe, 0, NULL, 0, INST_ACTION);
}

//写位置指令
//舵机ID[]数组，IDN数组长度，Position位置，运行时间Time，速度Speed
void SyncWritePos(uint8_t ID[], uint8_t IDN, uint16_t Position, uint16_t Time, uint16_t Speed)
{
	uint8_t buf[6];

	Host2SCS(buf+0, buf+1, Position);
	Host2SCS(buf+2, buf+3, 0);
	Host2SCS(buf+4, buf+5, Speed);
	snycWrite(ID, IDN, SCSCL_GOAL_POSITION_L, buf, 6);
}

//读位置，超时返回-1
int ReadPos(uint8_t ID)
{
	return readWord(ID, SCSCL_PRESENT_POSITION_L);
}

//速度控制模式
int WriteSpe(uint8_t ID, int16_t Speed)
{
	if(Speed<0){
		Speed = -Speed;
		Speed |= (1<<10);
	}
	return writeWord(ID, SCSCL_GOAL_TIME_L, Speed);
}

//读负载，超时返回-1
int ReadLoad(uint8_t ID)
{	
	return readWord(ID, SCSCL_PRESENT_LOAD_L);
}

//读电压，超时返回-1
 int ReadVoltage(uint8_t ID)
{	
	return readByte(ID, SCSCL_PRESENT_VOLTAGE);
}

//读温度，超时返回-1
int ReadTemper(uint8_t ID)
{	
	return readByte(ID, SCSCL_PRESENT_TEMPERATURE);
}

//Ping指令，返回舵机ID，超时返回-1
int Ping(uint8_t ID)
{
	int Size;
	uint8_t bBuf[6];
	flushSCS();
	writeBuf(ID, 0, NULL, 0, INST_PING);
	Size = readSCS(bBuf, 6);
	if(Size==6){
		return bBuf[2];
	}else{
		return -1;
	}
}

int wheelMode(uint8_t ID)
{
	uint8_t bBuf[4];
	bBuf[0] = 0;
	bBuf[1] = 0;
	bBuf[2] = 0;
	bBuf[3] = 0;
	return genWrite(ID, SCSCL_MIN_ANGLE_LIMIT_L, bBuf, 4);
}

int joinMode(uint8_t ID, uint16_t minAngle, uint16_t maxAngle) 
{
	uint8_t bBuf[4];
	Host2SCS(bBuf, bBuf+1, minAngle);
	Host2SCS(bBuf+2, bBuf+3, maxAngle);
	return genWrite(ID, SCSCL_MIN_ANGLE_LIMIT_L, bBuf, 4);
}
