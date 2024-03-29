<?php
// $Id$

/**
 * @file
 * User page callbacks for the forum module.
 */

/**
 * Menu callback; prints a forum listing.
 */
function forum_page($forum_term = NULL) {
  if (!isset($forum_term)) {
    // On the main page, display all the top-level forums.
    $forum_term = forum_forum_load(0);
  }

  $forum_per_page = variable_get('forum_per_page', 25);
  $sortby = variable_get('forum_order', 1);

  if (empty($forum_term->container)) {
    $topics = forum_get_topics($forum_term->tid, $sortby, $forum_per_page);
  }
  else {
    $topics = '';
  }

  return theme('forums', array('forums' => $forum_term->forums, 'topics' => $topics, 'parents' => $forum_term->parents, 'tid' => $forum_term->tid, 'sortby' => $sortby, 'forums_per_page' => $forum_per_page));
}
