#ifndef _SCSI_IOCTL_H
#define _SCSI_IOCTL_H 

#define SCSI_IOCTL_SEND_COMMAND 1
#define SCSI_IOCTL_TEST_UNIT_READY 2
#define SCSI_IOCTL_BENCHMARK_COMMAND 3
#define SCSI_IOCTL_SYNC 4			/* Request synchronous parameters */
#define SCSI_IOCTL_START_UNIT 5
#define SCSI_IOCTL_STOP_UNIT 6
#define SCSI_IOCTL_SECURITY_PROTOCOL_IN	7
#define SCSI_IOCTL_SECURITY_PROTOCOL_OUT 8
/* The door lock/unlock constants are compatible with Sun constants for
   the cdrom */
#define SCSI_IOCTL_DOORLOCK 0x5380		/* lock the eject mechanism */
#define SCSI_IOCTL_DOORUNLOCK 0x5381		/* unlock the mechanism	  */

#define	SCSI_REMOVAL_PREVENT	1
#define	SCSI_REMOVAL_ALLOW	0

#define SCSI_UFS_REQUEST_SENSE 0x6000		/* clear UAC in w-lun */

#ifdef __KERNEL__

struct scsi_device;

/*
 * Structures used for scsi_ioctl et al.
 */

typedef struct scsi_ioctl_command {
	unsigned int inlen;
	unsigned int outlen;
	unsigned char data[0];
} Scsi_Ioctl_Command;

typedef struct scsi_idlun {
	__u32 dev_id;
	__u32 host_unique_id;
} Scsi_Idlun;

/* Fibre Channel WWN, port_id struct */
typedef struct scsi_fctargaddress {
	__u32 host_port_id;
	unsigned char host_wwn[8]; // include NULL term.
} Scsi_FCTargAddress;

#if defined(CONFIG_SRPMB)
typedef struct rpmb_req {
	u32 cmd;
	volatile u32 status_flag;
	u32 type;
	u32 data_len;
	u32 inlen;
	u32 outlen;
	u8 rpmb_data[0];
} Rpmb_Req;

extern int srpmb_scsi_ioctl(struct scsi_device *, Rpmb_Req *req);
#endif

extern int scsi_ioctl(struct scsi_device *, int, void __user *);
extern int scsi_nonblockable_ioctl(struct scsi_device *sdev, int cmd,
				   void __user *arg, int ndelay);

#endif /* __KERNEL__ */
#endif /* _SCSI_IOCTL_H */