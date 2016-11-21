<?php
/**
 * @file
 */
use GraphQL\Type\Definition\Type;
use GraphQL\Type\Definition\ObjectType;

/**
 * Implements hook_graphql_info().
 *
 * @return array
 */
function graphql_api_graphql_api_info() {
  return [
    'types' => [
      'text_formatted' => new ObjectType([
        'name' => 'text_formatted',
        'fields' => [
          'value' => array(
            'type' => Type::string(),
            'description' => t('Text'),
          ),
          'summary' => array(
            'type' => Type::string(),
            'description' => t('Summary'),
          ),
          'format' => array(
            'type' => Type::string(),
            'description' => t('Text format'),
          ),
        ]
      ]),
      'field_item_file' => new ObjectType([
        'name' => 'field_item_file',
        'fields' => [
          'file' => [
            'type' => Type::string(),
            'description' => t('File')
          ],
          'description' => [
            'type' => Type::string(),
            'description' => t('Alt')
          ],
          'display' => [
            'type' => Type::string(),
            'description' => t('Display')
          ]
        ]
      ]),
      'field_item_image' => new ObjectType([
        'name' => 'field_item_image',
        'fields' => [
          'file' => [
            'type' => Type::string(),
            'description' => t('File')
          ],
          'description' => [
            'type' => Type::string(),
            'description' => t('Alt')
          ],
          'display' => [
            'type' => Type::string(),
            'description' => t('Display')
          ],
          'alt' => [
            'type' => Type::string(),
            'description' => t('Alt')
          ],
          'title' => [
            'type' => Type::string(),
            'description' => t('Title')
          ]
        ]
      ]),
    ]
  ];
}