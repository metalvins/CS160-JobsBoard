<?php
/**
 * @file
 * Provide views data and handlers for lifetime.module
 *
 * This exposes the average lifetime field to the views module for inclusion 
 * with other views. It sets up the display and sorting functions that are 
 * required by the field.
 */

/**
 * @defgroup views_lifetime_module lifetime.module handlers
 *
 * Includes the ability to create views of just the lifetime table.
 * @{
 */

/**
 * Implements hook_views_date()
 */
function lifetime_views_data() {
    // basic table information.

    // ----------------------------------------------------------
    // node_lifetime table
    $data['node_lifetime']['table']['group'] = t('Job lifetime');


    // Table join because nid in lifetime is the same as nid in table node
    $data['node_lifetime']['table']['join'] = array(
	'node' => array(
	    'left_field' => 'nid',
	    'field' => 'nid',
	),
    );

    // Expose the average lifetime field to views
    $data['node_lifetime']['avglifetime'] = array(
	'title' => t('Average lifetime'),
	'help' => t('The average time between publish and unpublish events'),

	// We have added a handler to views_handler_field_date which makes the
	// most sense because this is a time span.
	'field' => array(
	    'handler' => 'views_handler_field_date',
	    'click sortable' => TRUE,
	),

	// Raw value okay to sort here because it is an independent time span.
	'sort' => array(
	    'handler' => 'views_handler_sort', 
	),
    );

    return $data;
}
