#include"types.h"
struct vfs_inode{
 char * name;
 struct inode_operations ext2_ops * ops;
 struct inode_operations * iops;
// struct list_head fs_list;
};

struct inode_operations ext2_ops{
 
 struct inode * (* getroot )( int , int );
 struct inode * (* ialloc )( uint dev , short type );
 struct buf * (* bread )( uint dev , uint blockno );
 int (* fs_init )( void );
 int (* mount )( struct inode * devi , struct inode * ip );
 int (* unmount )( struct inode *);
 int (* namecmp )( const char *s , const char * t );
 void (* bzero )( int dev , int bno );
 void (* bfree )( int dev , uint b );
 void (* brelse )( struct buf * b );
 void (* bwrite )( struct buf * b );
 void (* readsb )( int dev , struct super_block * sb );    
 uint (* balloc )( uint dev );
};

struct inode_operations {
 struct inode * (* dirlookup )( struct inode * dp , char * name , uint * off );
 void (* iupdate )( struct inode * ip );
 void (* itrunc )( struct inode * ip );
 void (* cleanup )( struct inode * ip );
 void (* ilock )( struct inode * ip );
 void (* iunlock )( struct inode * ip );
 void (* stati )( struct inode * ip , struct stat * st );
 int (* readi )( struct inode * ip , char * dst , uint off , uint n );
 int (* writei )( struct inode * ip , char * src , uint off , uint n );
 int (* dirlink )( struct inode * dp , char * name , uint inum , uint type );
 int (* unlink )( struct inode * dp , uint off );
 int (* isdirempty )( struct inode * dp );
 uint (* bmap )( struct inode * ip , uint bn );

};
