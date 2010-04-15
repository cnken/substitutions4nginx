
#ifndef _NGX_HTTP_CHAIN_BUFFER_H_INCLUDED_
#define _NGX_HTTP_CHAIN_BUFFER_H_INCLUDED_

ngx_chain_t * get_chain_tail(ngx_chain_t *chain);
ngx_chain_t * get_chain_previous(ngx_chain_t *in, ngx_chain_t *chain);
ngx_buf_t * insert_shadow_tail(ngx_buf_t **p_shadow, ngx_buf_t *tail);
ngx_chain_t * insert_chain_tail(ngx_chain_t **p_chain, ngx_chain_t *tail);
ngx_chain_t *insert_chain_before( ngx_chain_t **p_in, ngx_chain_t *insert_chain, ngx_chain_t *chain);

ngx_buf_t * create_buffer(u_char *p, ngx_int_t len, ngx_pool_t *pool);

ngx_chain_t * create_chain_buffer(u_char *p, ngx_int_t len, ngx_pool_t *pool);
ngx_chain_t * duplicate_chain_buffer(u_char *p, ngx_int_t len, ngx_pool_t *pool);

/*read any chain's buffer and copy to *p_buff */
ngx_int_t chain_buffer_read( ngx_chain_t *chain, u_char **p_buff, 
        ngx_int_t *p_len, ngx_pool_t *pool);

/* Fetch a chain buffer, if *p_free is NULL, then create it, 
 * If not, allocates the head chain of *p_free for it.*/
ngx_chain_t * fetch_chain_buffer(u_char *p, ngx_int_t len, 
        ngx_chain_t **p_free, ngx_pool_t *pool);

/* Deep copy the chain's buffer and fetch a chain and buffer*/
ngx_chain_t * copy_chain_buffer(ngx_chain_t *chain, ngx_chain_t **p_free,
        ngx_pool_t *pool);

/* Deep copy chains, return the duplicate chains*/
ngx_chain_t * duplicate_chains(ngx_chain_t *chain, ngx_chain_t **p_free, 
        ngx_pool_t *pool);

/* delete the chains link of *p_chain and  
 * add to the head of *p_free_chain */
void delete_and_free_chain(ngx_chain_t **p_chain, ngx_chain_t **p_free_chain);

/* split the chain's buffer, len is the split point, 
 * *p_in is the chain's head*/
ngx_chain_t * split_chain( ngx_chain_t *chain,
        ngx_int_t len, ngx_chain_t **p_in, ngx_pool_t *pool);

/* fetch a body chain buffer first with *p and len, then fetch a 
 * replacement chain buffer with rep_str, and concatenate the 
 * chains of *p_in, boody and replacement chain.*/
ngx_int_t  buffer_chain_concatenate( ngx_chain_t **p_in, u_char *p, 
        ngx_int_t len, ngx_str_t *rep_str, ngx_pool_t *pool);

#endif /* _NGX_HTTP_CHAIN_BUFFER_H_INCLUDED_ */
