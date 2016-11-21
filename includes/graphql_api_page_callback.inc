<?php
use Drupal\graphql_api\Schema;
use GraphQL\GraphQL;

/**
 * Page callback for /graphql
 */
function graphql_api_page_callback() {
  $variables = [];
  if (isset($_SERVER['CONTENT_TYPE']) && strpos(strtolower($_SERVER['CONTENT_TYPE']), 'application/json') > -1) {
    $rawBody = file_get_contents('php://input');
    $data = drupal_json_decode($rawBody ?: '');
  } else {
    $data = $_POST;
  }

  if (!empty($data)) {
    if (empty($data['variables'])) {
      $data['variables'] = [];
    } else {
      $data['variables'] = drupal_json_decode($data['variables']);
    }
  }

  if (empty($data['query'])) {
    $data['query'] = file_get_contents(__DIR__ . '/../tests/fixtures/instrospec.graphql');
  }

  $requestString = isset($data['query']) ? $data['query'] : null;
  $operationName = isset($data['operation']) ? $data['operation'] : null;
  $variableValues = isset($data['variables']) ? $data['variables'] : null;

  try {
    // Define your schema:
    $schemaBuilder = new Schema;
    $schema = $schemaBuilder->build();
    $result = GraphQL::execute(
      $schema,
      $requestString,
      /* $rootValue */ null,
      /* $context */ null, // A custom context that can be used to pass current User object etc to all resolvers.
      $variableValues,
      $operationName
    );
  } catch (Exception $exception) {
    $result = [
      'errors' => [
        ['message' => $exception->getMessage(), 'backtrace' => debug_backtrace()]
      ]
    ];
  }

  drupal_json_output($result);
  exit;
}