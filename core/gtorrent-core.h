#ifndef GTORRENT_C_WRAPPER_H
#define GTORRENT_C_WRAPPER_H

#include <stdbool.h>
#include <stdint.h>

/*****************************************************************************/
/* gt::Core object */
struct gtorrent_core;
typedef struct gtorrent_core gtorrent_core;

/* gtorrent core functions */
gtorrent_core* core_create();

void        core_shutdown          (gtorrent_core *g);
void        update                 (gtorrent_core *g);

const char* get_default_save_path  (gtorrent_core *g);
bool        is_magnet_link         (gtorrent_core *g, char *link);
bool        is_running             (gtorrent_core *g);

/* Non-library core functions */
int32_t     get_number_torrents    (gtorrent_core *g);

/*****************************************************************************/
/* gt::Event object */
struct gtorrent_event;
typedef struct gtorrent_event gtorrent_event;

/* NOTE: Events aren't actually used for anything at the moment */

/*****************************************************************************/
/* gt::Torrent object */
struct gtorrent_torrent;
typedef struct gtorrent_torrent gtorrent_torrent;

/* get_torrents result must be freed manually */
gtorrent_torrent** get_torrents    (gtorrent_core *g);
gtorrent_torrent*  add_torrent     (gtorrent_core *g, char *path);

/* enum returned by get_state */
enum {
	TORRENT_STATE_CHECKING_FILES,
	TORRENT_STATE_SEEDING,
	TORRENT_STATE_DOWNLOADING
};

bool     poll_event                (gtorrent_torrent *t, gtorrent_event *e);
bool     is_paused                 (gtorrent_torrent *t);

int64_t  get_age                   (gtorrent_torrent *t);
int      get_state                 (gtorrent_torrent *t);
float    get_total_progress        (gtorrent_torrent *t);
uint32_t get_upload_rate           (gtorrent_torrent *t);
uint32_t get_download_rate         (gtorrent_torrent *t);
uint32_t get_ppm_progress          (gtorrent_torrent *t);
uint32_t get_total_seeders         (gtorrent_torrent *t);
uint32_t get_total_peers           (gtorrent_torrent *t);
uint32_t get_total_leechers        (gtorrent_torrent *t);
int64_t  get_total_uploaded        (gtorrent_torrent *t);
int64_t  get_total_downloaded      (gtorrent_torrent *t);
int64_t  get_size                  (gtorrent_torrent *t);
int64_t  get_wanted                (gtorrent_torrent *t);
int64_t  get_torrent_size          (gtorrent_torrent *t);
int64_t  get_time_remaining        (gtorrent_torrent *t);
float    get_total_ratio           (gtorrent_torrent *t);

char*    get_path                  (gtorrent_torrent *t);
char*    get_current_tracker_url   (gtorrent_torrent *t);
char*    get_text_age              (gtorrent_torrent *t);
char*    get_text_state            (gtorrent_torrent *t);
char*    get_text_upload_rate      (gtorrent_torrent *t);
char*    get_text_download_rate    (gtorrent_torrent *t);
char*    get_text_total_uploaded   (gtorrent_torrent *t);
char*    get_text_total_downloaded (gtorrent_torrent *t);
char*    get_text_size             (gtorrent_torrent *t);
char*    get_text_remaining        (gtorrent_torrent *t);
char*    get_text_total_ratio      (gtorrent_torrent *t);
char*    get_text_time_remaining   (gtorrent_torrent *t);

void     set_save_path             (gtorrent_torrent *t, char *path);
void     force_recheck             (gtorrent_torrent *t);
void     set_paused                (gtorrent_torrent *t, bool paused);
/* Conflicts with existing Unix functions, so 't_' is appended */
void     t_resume                  (gtorrent_torrent *t);
void     t_pause                   (gtorrent_torrent *t);

/* NOT IMPLEMENTED */
/*libtorrent::add_torrent_params getTorrentParams();*/
/*libtorrent::torrent_handle &getHandle();*/
/*void setHandle(libtorrent::torrent_handle &h);*/

/*****************************************************************************/
/* Log functions not implemented */

#endif
