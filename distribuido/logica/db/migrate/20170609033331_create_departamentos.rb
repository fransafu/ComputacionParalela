class CreateDepartamentos < ActiveRecord::Migration[5.0]
  def change
    create_table :departamentos do |t|
      t.string :nombre
      t.integer :facultad_id

      t.timestamps
    end
  end
end
