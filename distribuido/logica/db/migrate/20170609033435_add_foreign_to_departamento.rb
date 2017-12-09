class AddForeignToDepartamento < ActiveRecord::Migration[5.0]
  def change
    add_foreign_key :departamentos, :facultades, column: :facultad_id, primary_key: :id
  end
end
