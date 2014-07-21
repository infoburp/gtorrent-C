#ifndef GTORRENT_C_WRAPPER_H
#define GTORRENT_C_WRAPPER_H

#include <stdbool.h>
#include <stdint.h>

/*****************************************************************************/
/* gt::Core object */
struct gt_core;
typedef struct gt_core gt_core;

/* gtorrent core functions */
gt_core* core_create();

void        core_shutdown          (gt_core *g);
void        update                 (gt_core *g);

const char* get_default_save_path  (gt_core *g);
bool        is_magnet_link         (gt_core *g, char *link);
bool        is_running             (gt_core *g);

/* Non-library core functions */
int32_t     get_number_torrents    (gt_core *g);

/*****************************************************************************/
/* gt::Event object */
struct gt_event;
typedef struct gt_event gt_event;

/* NOTE: Events aren't actually used for anything at the moment */

/*****************************************************************************/
/* gt::Torrent object */
struct gt_torrent;
typedef struct gt_torrent gt_torrent;

/* get_torrents result must be freed manually */
gt_torrent** get_torrents    (gt_core *g);
gt_torrent*  add_torrent     (gt_core *g, char *path);

/* enum returned by get_state */
enum {
	TORRENT_STATE_CHECKING_FILES,
	TORRENT_STATE_SEEDING,
	TORRENT_STATE_DOWNLOADING
};

bool     poll_event                (gt_torrent *t, gt_event *e);
bool     is_paused                 (gt_torrent *t);

int64_t  get_active_time           (gt_torrent *t);
int      get_state                 (gt_torrent *t);
float    get_total_progress        (gt_torrent *t);
uint32_t get_upload_rate           (gt_torrent *t);
uint32_t get_download_rate         (gt_torrent *t);
uint32_t get_ppm_progress          (gt_torrent *t);
uint32_t get_total_seeders         (gt_torrent *t);
uint32_t get_total_peers           (gt_torrent *t);
uint32_t get_total_leechers        (gt_torrent *t);
int64_t  get_total_uploaded        (gt_torrent *t);
int64_t  get_total_downloaded      (gt_torrent *t);
int64_t  get_size                  (gt_torrent *t);
int64_t  get_wanted                (gt_torrent *t);
int64_t  get_torrent_size          (gt_torrent *t);
int64_t  get_time_remaining        (gt_torrent *t);
float    get_total_ratio           (gt_torrent *t);

char*    get_path                  (gt_torrent *t);
char*    get_current_tracker_url   (gt_torrent *t);
char*    get_text_active_time      (gt_torrent *t);
char*    get_text_state            (gt_torrent *t);
char*    get_text_upload_rate      (gt_torrent *t);
char*    get_text_download_rate    (gt_torrent *t);
char*    get_text_total_uploaded   (gt_torrent *t);
char*    get_text_total_downloaded (gt_torrent *t);
char*    get_text_size             (gt_torrent *t);
char*    get_text_remaining        (gt_torrent *t);
char*    get_text_total_ratio      (gt_torrent *t);
char*    get_text_time_remaining   (gt_torrent *t);

void     set_save_path             (gt_torrent *t, char *path);
/*void     force_recheck             (gt_torrent *t);*/
void     set_paused                (gt_torrent *t, bool paused);
/* Conflicts with existing Unix functions, so 't_' is prepended */
void     t_resume                  (gt_torrent *t);
void     t_pause                   (gt_torrent *t);

/* NOT IMPLEMENTED */
/*libtorrent::add_torrent_params getTorrentParams();*/
/*libtorrent::torrent_handle &getHandle();*/
/*void setHandle(libtorrent::torrent_handle &h);*/

/*****************************************************************************/
/* Log functions not implemented */

#endif
