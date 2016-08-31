// MESSAGE YOLO PACKING

#define MAVLINK_MSG_ID_YOLO 180

MAVPACKED(
typedef struct __mavlink_yolo_t {
 int32_t skip_en; /*< If cycle was skipped*/
 int32_t skip_count; /*< At what cycle to skip*/
}) mavlink_yolo_t;

#define MAVLINK_MSG_ID_YOLO_LEN 8
#define MAVLINK_MSG_ID_YOLO_MIN_LEN 8
#define MAVLINK_MSG_ID_180_LEN 8
#define MAVLINK_MSG_ID_180_MIN_LEN 8

#define MAVLINK_MSG_ID_YOLO_CRC 112
#define MAVLINK_MSG_ID_180_CRC 112



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_YOLO { \
	180, \
	"YOLO", \
	2, \
	{  { "skip_en", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_yolo_t, skip_en) }, \
         { "skip_count", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_yolo_t, skip_count) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_YOLO { \
	"YOLO", \
	2, \
	{  { "skip_en", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_yolo_t, skip_en) }, \
         { "skip_count", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_yolo_t, skip_count) }, \
         } \
}
#endif

/**
 * @brief Pack a yolo message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param skip_en If cycle was skipped
 * @param skip_count At what cycle to skip
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_yolo_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t skip_en, int32_t skip_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_YOLO_LEN];
	_mav_put_int32_t(buf, 0, skip_en);
	_mav_put_int32_t(buf, 4, skip_count);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_YOLO_LEN);
#else
	mavlink_yolo_t packet;
	packet.skip_en = skip_en;
	packet.skip_count = skip_count;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_YOLO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_YOLO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_YOLO_MIN_LEN, MAVLINK_MSG_ID_YOLO_LEN, MAVLINK_MSG_ID_YOLO_CRC);
}

/**
 * @brief Pack a yolo message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param skip_en If cycle was skipped
 * @param skip_count At what cycle to skip
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_yolo_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t skip_en,int32_t skip_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_YOLO_LEN];
	_mav_put_int32_t(buf, 0, skip_en);
	_mav_put_int32_t(buf, 4, skip_count);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_YOLO_LEN);
#else
	mavlink_yolo_t packet;
	packet.skip_en = skip_en;
	packet.skip_count = skip_count;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_YOLO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_YOLO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_YOLO_MIN_LEN, MAVLINK_MSG_ID_YOLO_LEN, MAVLINK_MSG_ID_YOLO_CRC);
}

/**
 * @brief Encode a yolo struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param yolo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_yolo_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_yolo_t* yolo)
{
	return mavlink_msg_yolo_pack(system_id, component_id, msg, yolo->skip_en, yolo->skip_count);
}

/**
 * @brief Encode a yolo struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param yolo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_yolo_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_yolo_t* yolo)
{
	return mavlink_msg_yolo_pack_chan(system_id, component_id, chan, msg, yolo->skip_en, yolo->skip_count);
}

/**
 * @brief Send a yolo message
 * @param chan MAVLink channel to send the message
 *
 * @param skip_en If cycle was skipped
 * @param skip_count At what cycle to skip
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_yolo_send(mavlink_channel_t chan, int32_t skip_en, int32_t skip_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_YOLO_LEN];
	_mav_put_int32_t(buf, 0, skip_en);
	_mav_put_int32_t(buf, 4, skip_count);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YOLO, buf, MAVLINK_MSG_ID_YOLO_MIN_LEN, MAVLINK_MSG_ID_YOLO_LEN, MAVLINK_MSG_ID_YOLO_CRC);
#else
	mavlink_yolo_t packet;
	packet.skip_en = skip_en;
	packet.skip_count = skip_count;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YOLO, (const char *)&packet, MAVLINK_MSG_ID_YOLO_MIN_LEN, MAVLINK_MSG_ID_YOLO_LEN, MAVLINK_MSG_ID_YOLO_CRC);
#endif
}

/**
 * @brief Send a yolo message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_yolo_send_struct(mavlink_channel_t chan, const mavlink_yolo_t* yolo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_yolo_send(chan, yolo->skip_en, yolo->skip_count);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YOLO, (const char *)yolo, MAVLINK_MSG_ID_YOLO_MIN_LEN, MAVLINK_MSG_ID_YOLO_LEN, MAVLINK_MSG_ID_YOLO_CRC);
#endif
}

#if MAVLINK_MSG_ID_YOLO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_yolo_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t skip_en, int32_t skip_count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, skip_en);
	_mav_put_int32_t(buf, 4, skip_count);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YOLO, buf, MAVLINK_MSG_ID_YOLO_MIN_LEN, MAVLINK_MSG_ID_YOLO_LEN, MAVLINK_MSG_ID_YOLO_CRC);
#else
	mavlink_yolo_t *packet = (mavlink_yolo_t *)msgbuf;
	packet->skip_en = skip_en;
	packet->skip_count = skip_count;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_YOLO, (const char *)packet, MAVLINK_MSG_ID_YOLO_MIN_LEN, MAVLINK_MSG_ID_YOLO_LEN, MAVLINK_MSG_ID_YOLO_CRC);
#endif
}
#endif

#endif

// MESSAGE YOLO UNPACKING


/**
 * @brief Get field skip_en from yolo message
 *
 * @return If cycle was skipped
 */
static inline int32_t mavlink_msg_yolo_get_skip_en(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field skip_count from yolo message
 *
 * @return At what cycle to skip
 */
static inline int32_t mavlink_msg_yolo_get_skip_count(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Decode a yolo message into a struct
 *
 * @param msg The message to decode
 * @param yolo C-struct to decode the message contents into
 */
static inline void mavlink_msg_yolo_decode(const mavlink_message_t* msg, mavlink_yolo_t* yolo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	yolo->skip_en = mavlink_msg_yolo_get_skip_en(msg);
	yolo->skip_count = mavlink_msg_yolo_get_skip_count(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_YOLO_LEN? msg->len : MAVLINK_MSG_ID_YOLO_LEN;
        memset(yolo, 0, MAVLINK_MSG_ID_YOLO_LEN);
	memcpy(yolo, _MAV_PAYLOAD(msg), len);
#endif
}
