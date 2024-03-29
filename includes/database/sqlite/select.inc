<?php
// $Id$

/**
 * @file
 * Select builder for SQLite embedded database engine.
 */

/**
 * @ingroup database
 * @{
 */

/**
 * SQLite specific query builder for SELECT statements.
 */
class SelectQuery_sqlite extends SelectQuery {
  public function forUpdate($set = TRUE) {
    // SQLite does not support FOR UPDATE so nothing to do.
    return $this;
  }
}

/**
 * @} End of "ingroup database".
 */


